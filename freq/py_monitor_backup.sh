#! /usr/bin/python3
def get_color(param):
	switcher = {
		0: '\033[1;31;31m',
		1: '\033[1;31;32m',
		2: '\033[1;31;33m',
		3: '\033[1;31;35m',
	}
	return switcher.get(param, '\033[1;31;38m')

def draw_chart(cpuinfo_cur_freq, cpuinfo_max_freq, color):
	normalized_cur_freq = int(cpuinfo_cur_freq / cpuinfo_max_freq * 100)
	
	i = 0
	while i < 100:
		if normalized_cur_freq > int(i):
			print('%s=' % color, end="")
		else:
			print(' ', end="")
		i += 1
	print('%s| %d Hz' % (color, cpuinfo_cur_freq))
	
	return

import os
import time

cpu_cpuinfo_max_freq = [0] * 16
cpu_cpuinfo_cur_freq = [0] * 16
cpu_num = 0
cpu_count = int(os.popen("sudo ls /sys/devices/system/cpu | grep cpu.*[0-9]$ | wc -l").read())

while True:
	cpu_cpuinfo_cur_freq[cpu_num] = int(os.popen("sudo cat /sys/devices/system/cpu/cpufreq/policy"+str(cpu_num)+"/cpuinfo_cur_freq").read())
	cpu_cpuinfo_max_freq[cpu_num] = int(os.popen("sudo cat /sys/devices/system/cpu/cpufreq/policy"+str(cpu_num)+"/cpuinfo_max_freq").read())

	draw_chart(cpu_cpuinfo_cur_freq[cpu_num], cpu_cpuinfo_max_freq[cpu_num], get_color(cpu_num))
	
	cpu_num += 1
	if cpu_num == cpu_count:
		time.sleep(1)
		cpu_num = 0
