##
## This file is part of the coreboot project.
##
## Copyright (C) 2012 Google Inc.
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; version 2 of the License.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

## DIMM SPD for on-board memory
SPD_BIN = $(obj)/spd.bin

# Order of names in SPD_SOURCES is important!
SPD_SOURCES  = Micron_4KTF25664HZ	# 0: 4GB / CH0 + CH1
SPD_SOURCES += Hynix_HMT425S6AFR6A	# 1: 4GB / CH0 + CH1
SPD_SOURCES += Elpida_EDJ4216EFBG	# 2: 4GB / CH0 + CH1
SPD_SOURCES += Hynix_HMT425S6CFR6A	# 3: 4GB / CH0 + CH1
SPD_SOURCES += Micron_4KTF25664HZ	# 4: 2GB / CH0 + CH1
SPD_SOURCES += Hynix_HMT425S6AFR6A	# 5: 2GB / CH0 + CH1
SPD_SOURCES += Elpida_EDJ4216EFBG	# 6: 2GB / CH0 + CH1
SPD_SOURCES += Hynix_HMT425S6CFR6A	# 7: 2GB / CH0 + CH1

SPD_DEPS := $(foreach f, $(SPD_SOURCES), src/mainboard/$(MAINBOARDDIR)/variants/$(VARIANT_DIR)/spd/$(f).spd.hex)

# Include spd ROM data
$(SPD_BIN): $(SPD_DEPS)
	for f in $+; \
	  do for c in $$(cat $$f | grep -v ^#); \
	    do printf $$(printf '\%o' 0x$$c); \
	  done; \
	done > $@

cbfs-files-y += spd.bin
spd.bin-file := $(SPD_BIN)
spd.bin-type := spd
