/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int gappx     = 12;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */

static const float systraysize = 0.75;
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 0;   /* systray spacing */

static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { 
  "monospace:size=15",
  "WenQuanYi Micro Hei:size=15:type=Regular:antialias=true:autoint=true",
  "Symbols Nerd Font:pixelsize=21:type=2048-em:antialias=true:autoint=true",
};
static const char dmenufont[]       = "WenQuanYi Micro Hei:size=24:type=Regular:antialias=true:autoint=true";

static const char col_gray1[]       = "#ffffff";
static const char col_gray2[]       = "#000000";
static const char col_gray3[]       = "#666666";
static const char col_gray4[]       = "#111111";
static const char col_gray5[]       = "#000000";
static const char col_cyan[]        = "#222222";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_gray1, col_cyan  },
	[SchemeBar]  = { col_gray1, col_gray5, col_cyan  },
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "󰲠","󰲢","󰲤", "󰈹", "󰣏", "󰎄", "󰘅", "󰘑", "󰕧"};

static const Rule rules[] = {  
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ NULL,        NULL,     "图片查看器",       0,             1,           -1 },   //QQ图片查看  
	{ NULL,        NULL,     "图片查看",         0,             1,           -1 },   //微信图片查看
	{ "listen1",   NULL,     NULL,               0,             1,           -1 },   //listen1     
};
/* layout(s) */
static const float mfact          = 0.6; /* factor of master area size [0.05..0.95] */
static const int   nmaster        = 1;    /* number of clients in master area */
static const int   resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int   lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
  { "",      tile },       /* first entry is default */
	{ "󰕰",      grid },       /* no layout function means floating behavior */
	{ "󰹞",      monocle },    /* no layout function means floating behavior */
//	{ "  ",      NULL },       /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      open,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2]          = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]    = { "dmenu_run", "-fn", dmenufont, "-c", "-l", "8", "-F", NULL};
static const char *termcmd[]     = { "st", NULL };
static const char *flameshot[]   = { "flameshot", "gui", NULL};
//static const char *firefoxcmd[]  = { "firefox", NULL };
//static const char *obsidiancmd[] = { "obsidian", NULL };

static const char *appcmds[50][50] = {
    { "",                    NULL },
    { "",                    NULL },
    { "",                    NULL },
    { "",                    NULL },
    { "firefox",             NULL },
    { "obsidian",            NULL },
    { "listen1",             NULL },
    { "linuxqq",             NULL },
    { "weixin",              NULL },
    { "obs",                 NULL },
};

static const Key keys[] = {
  /*                              键位                                */
	/* modifier                     key        function        argument */
	{ ControlMask|Mod1Mask,         XK_a,      spawn,          {.v = flameshot } },
	{ Mod1Mask,                     XK_space,  spawn,          {.v = dmenucmd } },


	{ MODKEY,                       XK_Up,      runcmd,          {.v = "amixer set Master 5%+"} },
	{ MODKEY,                       XK_Down,    runcmd,          {.v = "amixer set Master 5%-"} },

	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },

	{ ControlMask|ShiftMask,        XK_d,      killclient,     {0} },

	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

	{ Mod1Mask,                     XK_Tab,    NextCilent,     {.i = +1 } },
	{ Mod4Mask,             		    XK_Tab,    NextTag,	       {0} },

	{ MODKEY,                       XK_b,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_v,      incnmaster,     {.i = -1 } },

	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },

  { MODKEY,                       XK_f,      fullscreen,      {0} },

//  { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
//  { MODKEY,                       XK_space,  setlayout,      {0} },
//  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
//	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_o,                      3)
	TAGKEYS(                        XK_i,                      4)
	TAGKEYS(                        XK_m,                      5)

	TAGKEYS(                        XK_q,                      6)
	TAGKEYS(                        XK_w,                      7)
	TAGKEYS(                        XK_e,                      8)

	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        open,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

