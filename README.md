# QQ-dwm
QQ 基于 suckless 家 dwm 修改的 windows manager
 
## 使用说明

在使用前需要修改文件

1. 首先就是 config.mk 中, 将两项修改为自己的X11库位置
   ```c
   X11INC = /usr/include/X11
   X11LIB = /usr/lib/X11
   ```
2. 其次，在 Makefile 中, install位置的第一行QQWM_PATH为自己的配置
  ```c
  install: all
    echo "QQWM_PATH=/home/newbie/QQwm/dwm" >> /etc/environment
    mkdir -p ${DESTDIR}${PREFIX}/bin
    cp -f dwm ${DESTDIR}${PREFIX}/bin
    chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
    mkdir -p ${DESTDIR}${MANPREFIX}/man1
    sed "s/VERSION/${VERSION}/g" < dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
    chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1
    rm -f dwm ${OBJ} dwm-${VERSION}.tar.gz
  ```
3. 配置文件在 config.h 之中

### 桌面壁纸

### 开机启动项

### 快捷键

