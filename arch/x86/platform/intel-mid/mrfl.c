/*
 * mrfl.c: Intel Merrifield platform specific setup code
 *
 * (C) Copyright 2012 Intel Corporation
 * Author: Mark F. Brown <mark.f.brown@intel.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/module.h>
#include <linux/power_supply.h>
#include <linux/power/battery_id.h>
#include <asm/setup.h>
#include <asm/intel-mid.h>
#include <asm/processor.h>

#define APIC_DIVISOR 16
#define MRFL_I2_TERM_MA 120

//MD:add for SFI_TABLE_OEM0
#define SFI_TABLE_OEM0_SIZE 120


enum intel_mid_sim_type __intel_mid_sim_platform;
EXPORT_SYMBOL_GPL(__intel_mid_sim_platform);

static void (*intel_mid_timer_init)(void);
static struct ps_pse_mod_prof *battery_chrg_profile;
static struct ps_batt_chg_prof *ps_batt_chrg_profile;

static void tangier_arch_setup(void);

/* tangier arch ops */
static struct intel_mid_ops tangier_ops = {
	.arch_setup = tangier_arch_setup,
};

static unsigned long __init tangier_calibrate_tsc(void)
{
	/* [REVERT ME] fast timer calibration method to be defined */
	if ((intel_mid_identify_sim() == INTEL_MID_CPU_SIMULATION_VP) ||
	    (intel_mid_identify_sim() == INTEL_MID_CPU_SIMULATION_HVP)) {
		lapic_timer_frequency = 50000;
		return 1000000;
	}

	if ((intel_mid_identify_sim() == INTEL_MID_CPU_SIMULATION_SLE) ||
	    (intel_mid_identify_sim() == INTEL_MID_CPU_SIMULATION_NONE)) {

		unsigned long fast_calibrate;
		u32 lo, hi, ratio, fsb, bus_freq;

		/* *********************** */
		/* Compute TSC:Ratio * FSB */
		/* *********************** */

		/* Compute Ratio */
		rdmsr(MSR_PLATFORM_INFO, lo, hi);
		pr_debug("IA32 PLATFORM_INFO is 0x%x : %x\n", hi, lo);

		ratio = (lo >> 8) & 0xFF;
		pr_debug("ratio is %d\n", ratio);
		if (!ratio) {
			pr_err("Read a zero ratio, force tsc ratio to 4 ...\n");
			ratio = 4;
		}

		/* Compute FSB */
		rdmsr(MSR_FSB_FREQ, lo, hi);
		pr_debug("Actual FSB frequency detected by SOC 0x%x : %x\n",
			hi, lo);

		bus_freq = lo & 0x7;
		pr_debug("bus_freq = 0x%x\n", bus_freq);

		if (bus_freq == 0)
			fsb = FSB_FREQ_83SKU;
		else if (bus_freq == 1)
			fsb = FSB_FREQ_100SKU;
		else if (bus_freq == 2)
			fsb = FSB_FREQ_133SKU;
		else if (bus_freq == 3)
			fsb = FSB_FREQ_167SKU;
		else if (bus_freq == 4)
			fsb = FSB_FREQ_83SKU;
		else if (bus_freq == 5)
			fsb = FSB_FREQ_400SKU;
		else if (bus_freq == 6)
			fsb = FSB_FREQ_267SKU;
		else if (bus_freq == 7)
			fsb = FSB_FREQ_333SKU;
		else {
			BUG();
			pr_err("Invalid bus_freq! Setting to minimal value!\n");
			fsb = FSB_FREQ_100SKU;
		}

		/* TSC = FSB Freq * Resolved HFM Ratio */
		fast_calibrate = ratio * fsb;
		pr_debug("calculate tangier tsc %lu KHz\n", fast_calibrate);

		/* ************************************ */
		/* Calculate Local APIC Timer Frequency */
		/* ************************************ */
		lapic_timer_frequency = (fsb * 1000) / HZ;

		pr_debug("Setting lapic_timer_frequency = %d\n",
			lapic_timer_frequency);

		/* mark tsc clocksource as reliable */
		set_cpu_cap(&boot_cpu_data, X86_FEATURE_TSC_RELIABLE);

		if (fast_calibrate)
			return fast_calibrate;
	}
	return 0;
}

/* Allow user to enable simulator quirks settings for kernel */
static int __init set_simulation_platform(char *str)
{
	int platform;

	__intel_mid_sim_platform = INTEL_MID_CPU_SIMULATION_NONE;
	if (get_option(&str, &platform)) {
		__intel_mid_sim_platform = platform;
		pr_info("simulator mode %d enabled.\n",
			__intel_mid_sim_platform);
		return 0;
	}

	return -EINVAL;
}
early_param("mrfld_simulation", set_simulation_platform);

static void __init tangier_time_init(void)
{
	/* [REVERT ME] ARAT capability not set in VP. Force setting */
	if (intel_mid_identify_sim() == INTEL_MID_CPU_SIMULATION_VP ||
	    intel_mid_identify_sim() == INTEL_MID_CPU_SIMULATION_HVP)
		set_cpu_cap(&boot_cpu_data, X86_FEATURE_ARAT);

	if (intel_mid_timer_init)
		intel_mid_timer_init();
}

static void __init tangier_arch_setup(void)
{
	x86_platform.calibrate_tsc = tangier_calibrate_tsc;
	intel_mid_timer_init = x86_init.timers.timer_init;
	x86_init.timers.timer_init = tangier_time_init;
}

static void set_batt_chrg_prof(struct ps_pse_mod_prof *batt_prof,
				struct ps_pse_mod_prof *pentry)
{
	int i, j;

	if (batt_prof == NULL || pentry == NULL) {
		pr_err("%s: Invalid Pointer\n", __func__);
		return;
	}

	//memcpy(batt_prof->batt_id, pentry->batt_id, BATTID_STR_LEN);
	//batt_prof->battery_type = pentry->battery_type;
	//md modify for current battery
	//batt_prof->capacity = pentry->capacity;
	batt_prof->battery_type = 512;
	batt_prof->capacity = 4550;
	//batt_prof->voltage_max = pentry->voltage_max;
	batt_prof->voltage_max = 4360;
/*	
	if ((pentry->batt_id[0] == 'I') && (pentry->batt_id[1] == '2'))
		batt_prof->chrg_term_ma = MRFL_I2_TERM_MA;
	else
*/
	batt_prof->chrg_term_ma = 180;
	/*intel defult design
	  
		batt_prof->chrg_term_ma = pentry->chrg_term_ma;

	*/
	//add the bq24261 design
	batt_prof->low_batt_mV = 3400;
	batt_prof->disch_tmp_ul = 60;
	batt_prof->disch_tmp_ll = 0;
	batt_prof->temp_low_lim = 0;
	/*intel defult design
	  
	batt_prof->low_batt_mV = pentry->low_batt_mV;
	batt_prof->disch_tmp_ul = pentry->disch_tmp_ul;
	batt_prof->disch_tmp_ll = pentry->disch_tmp_ll;
	batt_prof->temp_low_lim = pentry->temp_low_lim;

	for (i = 0, j = 0; i < pentry->temp_mon_ranges; i++) {
		if (pentry->temp_mon_range[i].temp_up_lim != 0xff) {
			memcpy(&batt_prof->temp_mon_range[j],
			       &pentry->temp_mon_range[i],
			       sizeof(struct ps_temp_chg_table));
			j++;
		}
	}
	batt_prof->temp_mon_ranges = j;

	*/
	//add the bq24261 design 
	batt_prof->temp_mon_ranges = 4;
	batt_prof->temp_mon_range[0].temp_up_lim = 60;
	batt_prof->temp_mon_range[0].full_chrg_vol = 4360;
	batt_prof->temp_mon_range[0].full_chrg_cur = 1500;
	batt_prof->temp_mon_range[0].maint_chrg_vol_ll = 4100;
	batt_prof->temp_mon_range[0].maint_chrg_vol_ul = 4050;

	batt_prof->temp_mon_range[1].temp_up_lim = 45;
	batt_prof->temp_mon_range[1].full_chrg_vol = 4360;
	batt_prof->temp_mon_range[1].full_chrg_cur = 1500;
	batt_prof->temp_mon_range[1].maint_chrg_vol_ll = 4300;
	batt_prof->temp_mon_range[1].maint_chrg_vol_ul = 4360;

	batt_prof->temp_mon_range[2].temp_up_lim = 10;
	batt_prof->temp_mon_range[2].full_chrg_vol = 4360;
	batt_prof->temp_mon_range[2].full_chrg_cur = 1500;
	batt_prof->temp_mon_range[2].maint_chrg_vol_ll = 4300;
	batt_prof->temp_mon_range[2].maint_chrg_vol_ul = 4360;

	batt_prof->temp_mon_range[3].temp_up_lim = 0;
	batt_prof->temp_mon_range[3].full_chrg_vol = 4360;
	batt_prof->temp_mon_range[3].full_chrg_cur = 1500;
	batt_prof->temp_mon_range[3].maint_chrg_vol_ll = 4300;
	batt_prof->temp_mon_range[3].maint_chrg_vol_ul = 4360;
	pr_info("%s:have init the batt_prof.\n",__func__);
	return;
}
//MD: add for charger prof
void sfi_table_oem0_init(struct sfi_table_simple *sb)
{	
	struct sfi_table_header header;
	struct ps_pse_mod_prof *pentry;
	struct ps_pse_mod_prof *batt_prof;
	snprintf(sb->header.sig, 5,"%s","OEM0x");	
	sb->header.len = 120;
	sb->header.rev = 5;
	sb->header.csum = 144;
	snprintf(sb->header.oem_id, 7,"%s","Intel BATTERY");
	snprintf(sb->header.oem_table_id, 9,"%s","BATTERY");
	pr_info("%s:the battery is NULL.\n",__func__);
	pentry = (struct ps_pse_mod_prof *)sb->pentry;
	set_batt_chrg_prof(pentry,pentry);

}
extern void sfi_table_oem0_init(struct sfi_table_simple *sb);
static int __init mrfl_platform_init(void)
{
	struct sfi_table_simple *sb;
	struct ps_pse_mod_prof *pentry;
	int totentrs = 0, totlen = 0;
	struct sfi_table_header *table;

	table = get_oem0_table();

	if (!(INTEL_MID_BOARD(1, PHONE, MRFL) ||
	      INTEL_MID_BOARD(1, TABLET, MRFL) ||
		INTEL_MID_BOARD(1, PHONE, MOFD) ||
		 INTEL_MID_BOARD(1, TABLET, MOFD)))
		return 0;

	if (!table){
		sb = kzalloc( SFI_TABLE_OEM0_SIZE,GFP_KERNEL);
		if(!sb){
			pr_err("%s(): Error in kzalloc_sb\n", __func__);
			return -ENOMEM;
		}
		sfi_table_oem0_init(sb);
	}else
		sb = (struct sfi_table_simple *)table;
	if(sb==NULL){
		pr_info("%s: sfi_table_oem0 is NULL.\n");
		return 0;
	}
	pr_info("%s============.\n",__func__);
	pr_info("sb->header.sig:%s.\n",sb->header.sig);
	pr_info("sb->header.len:%d.\n",sb->header.len);
	pr_info("sb->header.rev:%d.\n",sb->header.rev);
	pr_info("sb->header.csum:0x%d.\n",sb->header.csum);
	pr_info("sb->header.oem_id:%s.\n",sb->header.oem_id);
	pr_info("sb->header.oem_table_id:%s.\n",sb->header.oem_table_id);
	totentrs = SFI_GET_NUM_ENTRIES(sb, struct ps_pse_mod_prof);
	pr_info("%s:totentrs:%d.\n",__func__,totentrs);
	if (totentrs) {
		battery_chrg_profile = kzalloc(
				sizeof(*battery_chrg_profile), GFP_KERNEL);
		if (!battery_chrg_profile) {
			pr_err("%s(): Error in kzalloc\n", __func__);
			return -ENOMEM;
		}
		pentry = (struct ps_pse_mod_prof *)sb->pentry;
		totlen = totentrs * sizeof(*pentry);
		if (totlen <= sizeof(*battery_chrg_profile)) {
			set_batt_chrg_prof(battery_chrg_profile, pentry);
			ps_batt_chrg_profile = kzalloc(
					sizeof(*ps_batt_chrg_profile),
					GFP_KERNEL);
			if (!ps_batt_chrg_profile) {
				pr_err("%s(): Error in kzalloc\n", __func__);
				kfree(battery_chrg_profile);
				return -ENOMEM;
			}
			ps_batt_chrg_profile->chrg_prof_type =
				PSE_MOD_CHRG_PROF;
			ps_batt_chrg_profile->batt_prof = battery_chrg_profile;
#ifdef CONFIG_POWER_SUPPLY_BATTID
			battery_prop_changed(POWER_SUPPLY_BATTERY_INSERTED,
					     ps_batt_chrg_profile);
#endif
		} else {
			pr_err("%s: Error in copying batt charge profile\n",
				__func__);
			kfree(battery_chrg_profile);
			return -ENOMEM;
		}
	} else {
		pr_err("%s: Error in finding batt charge profile\n",
			__func__);
	}

	return 0;
}
arch_initcall_sync(mrfl_platform_init);

void *get_tangier_ops()
{
	return &tangier_ops;
}

/* piggy back on anniedale ops right now */
void *get_anniedale_ops()
{
	return &tangier_ops;
}