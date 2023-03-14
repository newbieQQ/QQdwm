# QQ-dwm
QQ 基于 suckless 家 dwm 修改的 windows manager

## TODO

- [x] 实现alt+tab实现下一个窗口并且聚焦  
- [x] 实现win+tab实现下一个tag  
- [x] open函数，打开一个函数在特定tag  
- [x] 实现集成状态栏  
- [ ] 将系统托盘集成到状态栏  
- [ ] 将dmenu集成到软件里   
- [ ] 实现通知  
- [ ] 灵动岛  
- [x] 实现改键盘
- [ ] 实现u盘插入自动挂载
- [ ] 实现允许窗口浮动在各个tag上固定住

## 依赖的软件
```
picom             # 窗口渲染
feh               # 壁纸
alsa-utils        # 声音管理
blueman           # 蓝牙管理
keyd              # 键盘修改
```
 
## 使用说明

在使用前需要修改文件

1. 首先就是 config.mk 中, 将两项修改为自己的X11库位置
   ```bash
   X11INC = /usr/include/X11
   X11LIB = /usr/lib/X11
   ```
2. 其次，在 Makefile 中, install位置的第一行QQWM_PATH为自己的配置
  ```bash
  install: all
    echo "QQWM_PATH=/home/newbie/QQwm/dwm" >> /etc/environment
  ```
3. 配置文件在 config.h 之中

4. 修改键盘和窗口的渲染在config中, 用的分别是keyd和picom

### 桌面壁纸

### 开机启动项

### 快捷键

