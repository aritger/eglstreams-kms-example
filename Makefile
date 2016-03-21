# Copyright (c) 2016, NVIDIA CORPORATION. All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

SOURCES += main.c
SOURCES += egl.c
SOURCES += kms.c
SOURCES += utils.c
SOURCES += eglgears.c

HEADERS += egl.h
HEADERS += kms.h
HEADERS += utils.h
HEADERS += eglgears.h

OBJECTS = $(SOURCES:.c=.o)

EGLSTREAMS_KMS_EXAMPLE = eglstreams-kms-example

CFLAGS += -Wall -Wextra -g
CFLAGS += -I /usr/include/libdrm

# Use a current snapshot of EGL header files from Khronos
CFLAGS += -I khronos

%.o: %.c $(HEADERS)
	gcc -c $< -o $@ $(CFLAGS)

$(EGLSTREAMS_KMS_EXAMPLE): $(OBJECTS)
	gcc -o $@ $(OBJECTS) -lEGL -lOpenGL -ldrm -lm

clean:
	rm -f *.o $(EGLSTREAMS_KMS_EXAMPLE) *~
