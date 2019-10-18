sharedptr3:
	g++ the-cpp-std-lib/sharedptr3.cpp -std=c++1z -obin/sharedptr3 -lrt

udev_monitor_usb:
	gcc -Wall -g -o udev_monitor_usb udev_monitor_usb.c -ludev
