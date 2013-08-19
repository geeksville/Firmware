############################################################################
#
#   Copyright (C) 2012 PX4 Development Team. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name PX4 nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

#
# LUA library and command
#

MODULE_NAME		 = lua
MODULE_STACKSIZE	 = 8000

LUASRC		 = lib

# base sources
CSRCS		 = $(LUASRC)/lapi.c $(LUASRC)/lcode.c $(LUASRC)/lctype.c \
		   $(LUASRC)/ldebug.c $(LUASRC)/ldo.c $(LUASRC)/ldump.c \
		   $(LUASRC)/lfunc.c $(LUASRC)/lgc.c $(LUASRC)/llex.c \
		   $(LUASRC)/lmem.c $(LUASRC)/lobject.c $(LUASRC)/lopcodes.c \
		   $(LUASRC)/lparser.c $(LUASRC)/lstate.c $(LUASRC)/lstring.c \
		   $(LUASRC)/ltable.c $(LUASRC)/ltm.c $(LUASRC)/lundump.c \
		   $(LUASRC)/lvm.c $(LUASRC)/lzio.c $(LUASRC)/linit.c \
		   $(LUASRC)/loadlib.c

# libraries
CSRCS		+= $(LUASRC)/lauxlib.c
CSRCS		+= $(LUASRC)/lbaselib.c
CSRCS		+= $(LUASRC)/lbitlib.c
CSRCS		+= $(LUASRC)/lcorolib.c
CSRCS		+= $(LUASRC)/ldblib.c
CSRCS		+= $(LUASRC)/liolib.c
CSRCS		+= $(LUASRC)/lmathlib.c
CSRCS		+= $(LUASRC)/lstrlib.c
CSRCS		+= $(LUASRC)/ltablib.c
CSRCS		+= $(LUASRC)/loslib.c

# compatibility layer and shell
CSRCS		+= nuttx_lua_compat.c \
		   lua.c

# INCLUDES	 = $(LUASRC) $(APPDIR)/systemlib/linenoise

