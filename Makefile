sharedptr3:
	g++ the-cpp-std-lib/sharedptr3.cpp -std=c++1z -obin/sharedptr3 -lrt

udev_monitor_usb:
	gcc -Wall -g -o udev_monitor_usb misc/udev_monitor_usb.c -ludev

simple-threads:
	g++ concurrency/simple-threads.cpp -pthread -std=c++1z -obin/threads

parellel_loop:
	g++ -std=c++17 threadpool/parellel_loop.cpp -lpthread -obin/loop

synced_stream:
	g++ -std=c++17 threadpool/synced_stream.cpp -lpthread -obin/synced_stream