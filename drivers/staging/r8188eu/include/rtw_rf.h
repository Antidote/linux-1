/* SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause */
/* Copyright(c) 2007 - 2011 Realtek Corporation. */

#ifndef	__RTW_RF_H_
#define __RTW_RF_H_

#include "rtw_cmd.h"

#define OFDM_PHY		1
#define MIXED_PHY		2
#define CCK_PHY		3

#define NumRates	(13)

/*  slot time for 11g */
#define SHORT_SLOT_TIME			9
#define NON_SHORT_SLOT_TIME		20

#define RTL8711_RF_MAX_SENS		6
#define RTL8711_RF_DEF_SENS		4

/*  We now define the following channels as the max channels in each
 * channel plan. */
/*  2G, total 14 chnls */
/*  {1,2,3,4,5,6,7,8,9,10,11,12,13,14} */
#define	MAX_CHANNEL_NUM_2G		14
#define	MAX_CHANNEL_NUM			14	/* 2.4 GHz only */

#define NUM_REGULATORYS	1

/* Country codes */
#define USA				0x555320
#define EUROPE				0x1 /* temp, should be provided later */
#define JAPAN				0x2 /* temp, should be provided later */

struct	regulatory_class {
	u32	starting_freq;				/* MHz, */
	u8	channel_set[MAX_CHANNEL_NUM];
	u8	channel_cck_power[MAX_CHANNEL_NUM];	/* dbm */
	u8	channel_ofdm_power[MAX_CHANNEL_NUM];	/* dbm */
	u8	txpower_limit;				/* dbm */
	u8	channel_spacing;			/* MHz */
	u8	modem;
};

enum capability {
	cESS		= 0x0001,
	cIBSS		= 0x0002,
	cPollable	= 0x0004,
	cPollReq	= 0x0008,
	cPrivacy	= 0x0010,
	cShortPreamble	= 0x0020,
	cPBCC		= 0x0040,
	cChannelAgility	= 0x0080,
	cSpectrumMgnt	= 0x0100,
	cQos		= 0x0200,	/* For HCCA, use with CF-Pollable
					 * and CF-PollReq */
	cShortSlotTime	= 0x0400,
	cAPSD		= 0x0800,
	cRM		= 0x1000,	/*  RRM (Radio Request Measurement) */
	cDSSS_OFDM	= 0x2000,
	cDelayedBA	= 0x4000,
	cImmediateBA	= 0x8000,
};

enum	_REG_PREAMBLE_MODE {
	PREAMBLE_LONG	= 1,
	PREAMBLE_AUTO	= 2,
	PREAMBLE_SHORT	= 3,
};

enum rf90_radio_path {
	RF90_PATH_A = 0,		/* Radio Path A */
	RF90_PATH_B = 1,		/* Radio Path B */
	RF90_PATH_C = 2,		/* Radio Path C */
	RF90_PATH_D = 3			/* Radio Path D */
};

/*  Bandwidth Offset */
#define HAL_PRIME_CHNL_OFFSET_DONT_CARE	0
#define HAL_PRIME_CHNL_OFFSET_LOWER	1
#define HAL_PRIME_CHNL_OFFSET_UPPER	2

/*  Represent Channel Width in HT Capabilities */
/*  */
enum ht_channel_width {
	HT_CHANNEL_WIDTH_20 = 0,
	HT_CHANNEL_WIDTH_40 = 1,
};

/*  */
/*  Represent Extension Channel Offset in HT Capabilities */
/*  This is available only in 40Mhz mode. */
/*  */
enum ht_extchnl_offset {
	HT_EXTCHNL_OFFSET_NO_EXT = 0,
	HT_EXTCHNL_OFFSET_UPPER = 1,
	HT_EXTCHNL_OFFSET_NO_DEF = 2,
	HT_EXTCHNL_OFFSET_LOWER = 3,
};

u32 rtw_ch2freq(u32 ch);

#endif /* _RTL8711_RF_H_ */
