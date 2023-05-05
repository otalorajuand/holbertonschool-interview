#!/usr/bin/python3
"""This module prints stats"""
import sys



line_counter = 0
total_file_size = 0
status_codes = {'200': 0,
                '301': 0,
                '400': 0,
                '401': 0,
                '403': 0,
                '404': 0,
                '405': 0,
                '500': 0}

def print_stats(total_file_size, dic):
    print("File size: {}".format(total_file_size))
    for k, v in dic.items():
        if v != 0:
            print(k, v)

try: 
    for line in sys.stdin:
        line = line.rstrip()
 
        line_list = line.split(" ")
        status_code = str(line_list[7])

        if status_code in status_codes.keys():
            status_codes[status_code] += 1

        file_size = int(line_list[8])
        total_file_size += file_size

        if line_counter != 0 and line_counter % 10 == 0:
            print_stats(total_file_size, status_codes)
        line_counter += 1
    print_stats(total_file_size, status_codes)
except KeyboardInterrupt:
    print_stats(total_file_size, status_codes)
