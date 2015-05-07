#ifndef __COMMON_H__
#define __COMMON_H__

#define MAX_FPS_OPTIONS_SUPPORTED	3
#define I2C_MSG_LENGTH		0x2
#define E2PROM_2ADDR 0x80000000
#define E2PROM_ADDR_MASK 0x7fffffff

/* Defines for register writes and register array processing */
#define TSB_BYTE_MAX	32
#define TSB_SHORT_MAX	16
#define I2C_RETRY_COUNT		5
#define TSB_TOK_MASK	0xfff0

enum tsb_tok_type {
	TSB_8BIT  = 0x0001,
	TSB_16BIT = 0x0002,
	TSB_TOK_TERM   = 0xf000,	/* terminating token for reg list */
	TSB_TOK_DELAY  = 0xfe00	/* delay token for reg list */
};

/**
 * struct tsb_reg - MI sensor  register format
 * @type: type of the register
 * @reg: 16-bit offset to register
 * @val: 8/16/32-bit register value
 *
 * Define a structure for sensor register initialization values
 */
struct tsb_reg {
	enum tsb_tok_type type;
	u16 sreg;
	u32 val;	/* @set value for read/mod/write, @mask */
};

struct tsb_fps_setting {
	int fps;
	unsigned short pixels_per_line;
	unsigned short lines_per_frame;
	const struct tsb_reg *regs; /* regs that the fps setting needs */
};

struct tsb_resolution {
	const struct tsb_fps_setting fps_options[MAX_FPS_OPTIONS_SUPPORTED];
	u8 *desc;
	const struct tsb_reg *regs;
	int res;
	int width;
	int height;
	int fps;
	unsigned short pixels_per_line;
	unsigned short lines_per_frame;
	unsigned short skip_frames;
	u8 bin_factor_x;
	u8 bin_factor_y;
	bool used;
};

#define GROUPED_PARAMETER_HOLD_ENABLE  {TSB_8BIT, 0x0104, 0x1}
#define GROUPED_PARAMETER_HOLD_DISABLE  {TSB_8BIT, 0x0104, 0x0}

int tsb_write_reg(struct i2c_client *client, u16 data_length, u16 reg, u16 val);
#endif
