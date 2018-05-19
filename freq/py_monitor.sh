#! /usr/bin/python3
def get_color(param):
	switcher = {
		0: '\033[1;31;31m',
		1: '\033[1;31;32m',
		2: '\033[1;31;33m',
		3: '\033[1;31;35m',
	}
	return switcher.get(param, '\033[1;31;38m')

def draw_chart(cpuinfo_cur_freq, scaling_max_freq, color):
	normalized_cur_freq = int(cpuinfo_cur_freq / scaling_max_freq * 100)
	
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

cpu_scaling_max_freq = [0] * 99999999
cpu_cpuinfo_cur_freq = [0] * 99999999
cpu_count = int(os.popen("nproc").read())
cpu_cpuinfo_max_freq = [0] * cpu_count
i = 0
while i < cpu_count:
	cpu_cpuinfo_max_freq[i] = int(os.popen("cat /sys/devices/system/cpu/cpufreq/policy"+str(i)+"/cpuinfo_max_freq").read())
	i += 1

#i = 0
#while i < cpu_count:
#	print(cpu_cpuinfo_max_freq[i])
#	i += 1

i = 0
cpu_index = 0
while True:
#	print(i)
	cpu_cpuinfo_cur_freq[i] = int(os.popen("cat /sys/devices/system/cpu/cpufreq/policy"+str(cpu_index)+"/cpuinfo_cur_freq").read())
	cpu_scaling_max_freq[i] = int(os.popen("cat /sys/devices/system/cpu/cpufreq/policy"+str(cpu_index)+"/scaling_max_freq").read())
#
#	draw_chart(cpu_cpuinfo_cur_freq[i], cpu_scaling_max_freq[i], get_color(i))
#	
	i += 1
	cpu_index += 1
	if cpu_index == cpu_count:
		cpu_index = 0