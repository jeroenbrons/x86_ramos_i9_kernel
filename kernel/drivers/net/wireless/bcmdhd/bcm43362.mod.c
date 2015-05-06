#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x5a41a61d, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x1a3cd055, __VMLINUX_SYMBOL_STR(register_netdevice) },
	{ 0xa12fcae0, __VMLINUX_SYMBOL_STR(sdio_writeb) },
	{ 0xc689965, __VMLINUX_SYMBOL_STR(sdio_readb) },
	{ 0x3ce4ca6f, __VMLINUX_SYMBOL_STR(disable_irq) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0x97164db6, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0x5dce6b75, __VMLINUX_SYMBOL_STR(complete_and_exit) },
	{ 0xd5baf626, __VMLINUX_SYMBOL_STR(wiphy_free) },
	{ 0x6516b543, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0x9d7b5a17, __VMLINUX_SYMBOL_STR(mem_map) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0x15692c87, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xd0d8621b, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xc7ec6c27, __VMLINUX_SYMBOL_STR(strspn) },
	{ 0x48d587b8, __VMLINUX_SYMBOL_STR(wakeup_source_add) },
	{ 0xd03c4b47, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0x7ffc8718, __VMLINUX_SYMBOL_STR(gpio_set_debounce) },
	{ 0x27bbf221, __VMLINUX_SYMBOL_STR(disable_irq_nosync) },
	{ 0x9c64fbd, __VMLINUX_SYMBOL_STR(ieee80211_frequency_to_channel) },
	{ 0xf68285c0, __VMLINUX_SYMBOL_STR(register_inetaddr_notifier) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x1258d9d9, __VMLINUX_SYMBOL_STR(regulator_disable) },
	{ 0x79ac8d5, __VMLINUX_SYMBOL_STR(send_sig) },
	{ 0xd2d4dac8, __VMLINUX_SYMBOL_STR(__pm_stay_awake) },
	{ 0x3a013b7d, __VMLINUX_SYMBOL_STR(remove_wait_queue) },
	{ 0x9aca444b, __VMLINUX_SYMBOL_STR(get_monotonic_boottime) },
	{ 0xd52610f6, __VMLINUX_SYMBOL_STR(cfg80211_inform_bss_frame) },
	{ 0x830d54cd, __VMLINUX_SYMBOL_STR(sdio_enable_func) },
	{ 0xc7a4fbed, __VMLINUX_SYMBOL_STR(rtnl_lock) },
	{ 0x47229b5c, __VMLINUX_SYMBOL_STR(gpio_request) },
	{ 0xa4eb4eff, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0x48ca8947, __VMLINUX_SYMBOL_STR(pm_qos_add_request) },
	{ 0x67643d26, __VMLINUX_SYMBOL_STR(pm_qos_remove_request) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0x2addc0be, __VMLINUX_SYMBOL_STR(down_interruptible) },
	{ 0xd2da1048, __VMLINUX_SYMBOL_STR(register_netdevice_notifier) },
	{ 0x4205ad24, __VMLINUX_SYMBOL_STR(cancel_work_sync) },
	{ 0x60352082, __VMLINUX_SYMBOL_STR(register_inet6addr_notifier) },
	{ 0xe2fae716, __VMLINUX_SYMBOL_STR(kmemdup) },
	{ 0xcd431b6, __VMLINUX_SYMBOL_STR(cfg80211_rx_mgmt) },
	{ 0x5a15660a, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0xa1425906, __VMLINUX_SYMBOL_STR(ieee80211_channel_to_frequency) },
	{ 0x791bb067, __VMLINUX_SYMBOL_STR(x86_dma_fallback_dev) },
	{ 0x4e830a3e, __VMLINUX_SYMBOL_STR(strnicmp) },
	{ 0x1976aa06, __VMLINUX_SYMBOL_STR(param_ops_bool) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x24d7b4eb, __VMLINUX_SYMBOL_STR(cancel_delayed_work_sync) },
	{ 0x70501961, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x4cabed9, __VMLINUX_SYMBOL_STR(rfkill_register) },
	{ 0x2e8b6c8c, __VMLINUX_SYMBOL_STR(__pm_wakeup_event) },
	{ 0x86bd959e, __VMLINUX_SYMBOL_STR(cfg80211_del_sta) },
	{ 0x849f23fb, __VMLINUX_SYMBOL_STR(cfg80211_unregister_wdev) },
	{ 0x7fe1a403, __VMLINUX_SYMBOL_STR(cfg80211_find_ie) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x6619cbe, __VMLINUX_SYMBOL_STR(skb_realloc_headroom) },
	{ 0x45415728, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xa9d8dc69, __VMLINUX_SYMBOL_STR(sdio_get_host_pm_caps) },
	{ 0x9d0d6206, __VMLINUX_SYMBOL_STR(unregister_netdevice_notifier) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0xb43c8fda, __VMLINUX_SYMBOL_STR(cfg80211_mgmt_tx_status) },
	{ 0x4d405db8, __VMLINUX_SYMBOL_STR(param_ops_string) },
	{ 0xce2840e7, __VMLINUX_SYMBOL_STR(irq_set_irq_wake) },
	{ 0xec52c6d4, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0x51c0673b, __VMLINUX_SYMBOL_STR(netif_rx) },
	{ 0x82f89884, __VMLINUX_SYMBOL_STR(wakeup_source_prepare) },
	{ 0x34757328, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0x68dfc59f, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xffd5a395, __VMLINUX_SYMBOL_STR(default_wake_function) },
	{ 0xd11f0209, __VMLINUX_SYMBOL_STR(mmc_wait_for_req) },
	{ 0x2fe252cc, __VMLINUX_SYMBOL_STR(unregister_inet6addr_notifier) },
	{ 0x3fa58ef8, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0x13b452e9, __VMLINUX_SYMBOL_STR(kernel_read) },
	{ 0xdd0a2ba2, __VMLINUX_SYMBOL_STR(strlcat) },
	{ 0x46b08ea9, __VMLINUX_SYMBOL_STR(sdio_writel) },
	{ 0xd5f2172f, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xb5eeb329, __VMLINUX_SYMBOL_STR(register_early_suspend) },
	{ 0xc6fd339e, __VMLINUX_SYMBOL_STR(netif_rx_ni) },
	{ 0x159900c0, __VMLINUX_SYMBOL_STR(__ieee80211_get_channel) },
	{ 0x65d6d0f0, __VMLINUX_SYMBOL_STR(gpio_direction_input) },
	{ 0xf97456ea, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0xea65b389, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x7580c361, __VMLINUX_SYMBOL_STR(cfg80211_get_bss) },
	{ 0x698bd4f7, __VMLINUX_SYMBOL_STR(__pskb_copy) },
	{ 0x37befc70, __VMLINUX_SYMBOL_STR(jiffies_to_msecs) },
	{ 0x9aaa54f0, __VMLINUX_SYMBOL_STR(rfkill_alloc) },
	{ 0xb3242aa2, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x6a145f58, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x5152e605, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x992dd7e8, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0xd6c9523, __VMLINUX_SYMBOL_STR(wiphy_unregister) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0xb6ed1e53, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x2da418b5, __VMLINUX_SYMBOL_STR(copy_to_user) },
	{ 0x94e0e558, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0x34979ece, __VMLINUX_SYMBOL_STR(mmc_set_data_timeout) },
	{ 0x2a2248ca, __VMLINUX_SYMBOL_STR(sdio_readl) },
	{ 0x6c2e3320, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x6e9cbbac, __VMLINUX_SYMBOL_STR(pci_bus_write_config_dword) },
	{ 0xce7ea677, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0xcbfa4681, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x991b1681, __VMLINUX_SYMBOL_STR(cfg80211_connect_result) },
	{ 0x787cba13, __VMLINUX_SYMBOL_STR(dev_close) },
	{ 0xa23ef122, __VMLINUX_SYMBOL_STR(cfg80211_michael_mic_failure) },
	{ 0x6e5f148e, __VMLINUX_SYMBOL_STR(wiphy_apply_custom_regulatory) },
	{ 0x1e6d26a8, __VMLINUX_SYMBOL_STR(strstr) },
	{ 0xdd1a2871, __VMLINUX_SYMBOL_STR(down) },
	{ 0x3d42042a, __VMLINUX_SYMBOL_STR(platform_get_resource) },
	{ 0x9545af6d, __VMLINUX_SYMBOL_STR(tasklet_init) },
	{ 0x8834396c, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0xbe2c0274, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0xa735db59, __VMLINUX_SYMBOL_STR(prandom_u32) },
	{ 0xbed4afba, __VMLINUX_SYMBOL_STR(dma_release_from_coherent) },
	{ 0xd6b8e852, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0x5ecbe7e, __VMLINUX_SYMBOL_STR(platform_driver_register) },
	{ 0x2fb81c3f, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x310917fe, __VMLINUX_SYMBOL_STR(sort) },
	{ 0x610f0577, __VMLINUX_SYMBOL_STR(cfg80211_ibss_joined) },
	{ 0xc733518d, __VMLINUX_SYMBOL_STR(dev_kfree_skb_any) },
	{ 0xd550560f, __VMLINUX_SYMBOL_STR(__pm_relax) },
	{ 0xd79b5a02, __VMLINUX_SYMBOL_STR(allow_signal) },
	{ 0xdd40bdcf, __VMLINUX_SYMBOL_STR(dma_alloc_from_coherent) },
	{ 0x61651be, __VMLINUX_SYMBOL_STR(strcat) },
	{ 0x82072614, __VMLINUX_SYMBOL_STR(tasklet_kill) },
	{ 0x216bd7f3, __VMLINUX_SYMBOL_STR(sdio_readsb) },
	{ 0x392b018, __VMLINUX_SYMBOL_STR(sdio_unregister_driver) },
	{ 0x935038e5, __VMLINUX_SYMBOL_STR(sdio_f0_writeb) },
	{ 0xfea7e969, __VMLINUX_SYMBOL_STR(sdio_set_host_pm_flags) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0x9f984513, __VMLINUX_SYMBOL_STR(strrchr) },
	{ 0x11f447ce, __VMLINUX_SYMBOL_STR(__gpio_to_irq) },
	{ 0xe03382e2, __VMLINUX_SYMBOL_STR(cfg80211_roamed) },
	{ 0xe3638eb3, __VMLINUX_SYMBOL_STR(cfg80211_put_bss) },
	{ 0x93b37ebb, __VMLINUX_SYMBOL_STR(wiphy_new) },
	{ 0x42c8de35, __VMLINUX_SYMBOL_STR(ioremap_nocache) },
	{ 0xfe029963, __VMLINUX_SYMBOL_STR(unregister_inetaddr_notifier) },
	{ 0x12a38747, __VMLINUX_SYMBOL_STR(usleep_range) },
	{ 0x5c52392, __VMLINUX_SYMBOL_STR(wiphy_register) },
	{ 0x9a63ce7d, __VMLINUX_SYMBOL_STR(pci_bus_read_config_dword) },
	{ 0x8bf826c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xe851bb05, __VMLINUX_SYMBOL_STR(queue_delayed_work_on) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0x4c4cd1a0, __VMLINUX_SYMBOL_STR(cfg80211_ready_on_channel) },
	{ 0x480af0c3, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0xeb7b9dab, __VMLINUX_SYMBOL_STR(sdio_f0_readb) },
	{ 0x7f24de73, __VMLINUX_SYMBOL_STR(jiffies_to_usecs) },
	{ 0x37b1f4b3, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xf7650d47, __VMLINUX_SYMBOL_STR(pskb_expand_head) },
	{ 0x318d62c3, __VMLINUX_SYMBOL_STR(cfg80211_disconnected) },
	{ 0x64b8e45b, __VMLINUX_SYMBOL_STR(mmc_power_save_host) },
	{ 0xd9435df, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x21fb443e, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x7afa89fc, __VMLINUX_SYMBOL_STR(vsnprintf) },
	{ 0xece098ff, __VMLINUX_SYMBOL_STR(cfg80211_new_sta) },
	{ 0x17cb91c8, __VMLINUX_SYMBOL_STR(sched_setscheduler) },
	{ 0xe45f60d8, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x351b6d64, __VMLINUX_SYMBOL_STR(mmc_power_restore_host) },
	{ 0xf6ebc03b, __VMLINUX_SYMBOL_STR(net_ratelimit) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0x448d44fd, __VMLINUX_SYMBOL_STR(sdio_memcpy_toio) },
	{ 0xfe990052, __VMLINUX_SYMBOL_STR(gpio_free) },
	{ 0x3ce7b6cf, __VMLINUX_SYMBOL_STR(sdio_writew) },
	{ 0xd7bd3af2, __VMLINUX_SYMBOL_STR(add_wait_queue) },
	{ 0xfcec0987, __VMLINUX_SYMBOL_STR(enable_irq) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xdb68bbad, __VMLINUX_SYMBOL_STR(rfkill_destroy) },
	{ 0x622fa02a, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0x2bf8d577, __VMLINUX_SYMBOL_STR(sleep_on_timeout) },
	{ 0xedc03953, __VMLINUX_SYMBOL_STR(iounmap) },
	{ 0xd85ac634, __VMLINUX_SYMBOL_STR(regulator_put) },
	{ 0xc4554217, __VMLINUX_SYMBOL_STR(up) },
	{ 0x8effebd3, __VMLINUX_SYMBOL_STR(pm_qos_update_request) },
	{ 0x75bb675a, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xb227ae83, __VMLINUX_SYMBOL_STR(unregister_early_suspend) },
	{ 0xc15ed807, __VMLINUX_SYMBOL_STR(cfg80211_remain_on_channel_expired) },
	{ 0xd15e4af8, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0xb742fd7, __VMLINUX_SYMBOL_STR(simple_strtol) },
	{ 0xb2d48a2e, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x19a9e62b, __VMLINUX_SYMBOL_STR(complete) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xafb8d4f7, __VMLINUX_SYMBOL_STR(__netif_schedule) },
	{ 0x8235805b, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x28fbdf98, __VMLINUX_SYMBOL_STR(sdio_readw) },
	{ 0x20db8c48, __VMLINUX_SYMBOL_STR(sdio_register_driver) },
	{ 0x8aae014a, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x5e18048f, __VMLINUX_SYMBOL_STR(sdio_memcpy_fromio) },
	{ 0xa81770f4, __VMLINUX_SYMBOL_STR(sdio_claim_host) },
	{ 0x76740bfc, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x85670f1d, __VMLINUX_SYMBOL_STR(rtnl_is_locked) },
	{ 0xc1b9ccbf, __VMLINUX_SYMBOL_STR(cfg80211_scan_done) },
	{ 0x83eb21c, __VMLINUX_SYMBOL_STR(rfkill_unregister) },
	{ 0xb1d9523e, __VMLINUX_SYMBOL_STR(wait_for_completion_timeout) },
	{ 0x33d169c9, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0xe5d95985, __VMLINUX_SYMBOL_STR(param_ops_ulong) },
	{ 0x6d044c26, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x75f8fc13, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0xb326f2e4, __VMLINUX_SYMBOL_STR(down_timeout) },
	{ 0x5366c204, __VMLINUX_SYMBOL_STR(sdio_set_block_size) },
	{ 0xdc59a32f, __VMLINUX_SYMBOL_STR(wakeup_source_drop) },
	{ 0x6e720ff2, __VMLINUX_SYMBOL_STR(rtnl_unlock) },
	{ 0x9e7d6bd0, __VMLINUX_SYMBOL_STR(__udelay) },
	{ 0x48f15205, __VMLINUX_SYMBOL_STR(sdhci_pci_request_regulators) },
	{ 0xd217ce9f, __VMLINUX_SYMBOL_STR(wakeup_source_remove) },
	{ 0x1ab05107, __VMLINUX_SYMBOL_STR(dma_ops) },
	{ 0xce535262, __VMLINUX_SYMBOL_STR(sdio_disable_func) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0xca16dbe7, __VMLINUX_SYMBOL_STR(regulator_enable) },
	{ 0xc4eae512, __VMLINUX_SYMBOL_STR(sdio_release_host) },
	{ 0xe9920c28, __VMLINUX_SYMBOL_STR(filp_open) },
	{ 0xc4c810e, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
	{ 0xb5229bdc, __VMLINUX_SYMBOL_STR(cfg80211_sched_scan_results) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=cfg80211";

MODULE_ALIAS("sdio:c*v02D0d4334*");
MODULE_ALIAS("sdio:c*v02D0dA94D*");
MODULE_ALIAS("sdio:c*v02D0d4324*");
MODULE_ALIAS("sdio:c*v02D0d4335*");
MODULE_ALIAS("sdio:c*v02D0dA962*");
MODULE_ALIAS("of:N*T*Candroid,bcmdhd_wlan*");
