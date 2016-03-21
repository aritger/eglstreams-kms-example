/*
 * Copyright (c) 2016, NVIDIA CORPORATION. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "utils.h"
#include "egl.h"
#include "kms.h"
#include "eglgears.h"

/*
 * Example code demonstrating how to connect EGL to DRM KMS using
 * EGLStreams.
 */

int main(void)
{
    EGLDisplay eglDpy;
    EGLDeviceEXT eglDevice;
    int drmFd, width, height;
    uint32_t planeID = 0;
    EGLSurface eglSurface;

    GetEglExtensionFunctionPointers();

    eglDevice = GetEglDevice();

    drmFd = GetDrmFd(eglDevice);

    SetMode(drmFd, &planeID, &width, &height);

    eglDpy = GetEglDisplay(eglDevice, drmFd);

    eglSurface = SetUpEgl(eglDpy, planeID, width, height);

    InitGears(width, height);

    while(1) {
        DrawGears();
        eglSwapBuffers(eglDpy, eglSurface);
        PrintFps();
    }

    return 0;
}
