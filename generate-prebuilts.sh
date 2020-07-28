#!/bin/sh
PYTHONDONTWRITEBYTECODE=1 src/gallium/auxiliary/util/u_format_table.py \
  >$PWD/prebuilt-intermediates/src/u_format_table.c
