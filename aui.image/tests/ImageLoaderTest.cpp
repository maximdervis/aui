// AUI Framework - Declarative UI toolkit for modern C++17
// Copyright (C) 2020-2023 Alex2772
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library. If not, see <http://www.gnu.org/licenses/>.

#include <gtest/gtest.h>
#include "AUI/Common/AByteBufferView.h"
#include "AUI/Image/AImage.h"
#include "AUI/Util/ABuiltinFiles.h"

const static unsigned char AUI_PACKED_assettarget[] = {0x78,0xda,0xed,0xce,0xdb,0x4b,0xd3,0x71,0x18,0xc7,0xf1,0x9f,0x75,0x11,0x3c,0x41,0x17,0x75,0x51,0xd0,0x81,0x22,0x0a,0x29,0x8a,0x84,0x30,0x29,0xe8,0x20,0x24,0x14,0x06,0x82,0x41,0x51,0x11,0x6a,0xd4,0x18,0x61,0xb3,0x1a,0x45,0x30,0xca,0xc8,0x0e,0x88,0x44,0xb2,0x40,0x4b,0xb0,0x24,0x63,0x41,0x43,0x26,0x99,0x21,0x28,0x24,0x34,0x92,0x50,0x22,0x72,0x38,0x75,0xb4,0x43,0x73,0x4b,0x5b,0x53,0x9b,0xb3,0x16,0xe1,0xd3,0xec,0xf0,0x27,0xbc,0x91,0x60,0x0f,0xaf,0xcf,0xf7,0xe2,0xf7,0xbb,0x79,0x8b,0x61,0x18,0xd6,0xd2,0x73,0xa6,0x93,0xd6,0xcd,0x65,0xe5,0x15,0x79,0x5b,0x0c,0x23,0xff,0xc0,0xec,0x3b,0x7b,0xb9,0xe9,0x65,0xa7,0xb7,0xfb,0xef,0xb2,0x8c,0x65,0xbf,0xbf,0xcf,0x4b,0xff,0x5f,0xbc,0xf0,0xcf,0xfe,0x9d,0xc7,0xc2,0xba,0xb2,0x5c,0x50,0x74,0x7f,0xe5,0x4a,0x41,0xd1,0xfd,0xd7,0x56,0x09,0x8a,0xee,0xaf,0x5a,0x2d,0x28,0xba,0xff,0xe6,0x5a,0x41,0x79,0x2c,0x59,0xa8,0xea,0x75,0x82,0x1a,0x38,0x3b,0x1f,0x75,0x3b,0x5b,0x50,0xde,0xf3,0x0b,0x50,0xb5,0x1b,0x04,0xe5,0xbd,0xc0,0xba,0xbb,0x89,0x35,0x78,0x69,0x11,0xaa,0x2e,0x47,0x50,0x43,0xb6,0x25,0xa8,0x86,0xad,0x82,0xf2,0x5d,0x5e,0x8a,0x6a,0xda,0x26,0x28,0xff,0xd5,0x15,0xa8,0xe6,0xed,0x82,0x0a,0x5c,0x5f,0x83,0x72,0xec,0x14,0x54,0xe8,0xd6,0x7a,0x94,0x33,0x5f,0x50,0xe1,0x9a,0x8d,0x28,0x57,0x81,0xa0,0x22,0x77,0x72,0x50,0x6d,0xfb,0x04,0x15,0xb5,0xe7,0xa2,0x3a,0x0a,0x05,0xf5,0xa9,0x6e,0x07,0xaa,0xb3,0x48,0x50,0x9f,0xef,0xef,0x41,0x75,0x17,0x0b,0xea,0x4b,0xe3,0x5e,0x94,0xfb,0x90,0xa0,0xe2,0x4d,0xfb,0x51,0x3d,0x47,0x05,0x35,0xd1,0x5c,0x84,0xea,0x3d,0x2e,0xa8,0xaf,0x4f,0x0e,0xa2,0xde,0x96,0x08,0x2a,0xf1,0xf4,0x30,0xaa,0xbf,0x4c,0x50,0x53,0x2d,0xc7,0x50,0x03,0xa7,0x04,0x95,0x74,0x95,0xa2,0x06,0xcd,0x82,0x9a,0x6e,0x3d,0x81,0xf2,0x9d,0x16,0xd4,0xb7,0x67,0x26,0x94,0xbf,0x5c,0x50,0xa9,0xe7,0x66,0x54,0xc0,0x22,0xa8,0x54,0xbb,0x19,0x15,0xaa,0x10,0xd4,0xff,0xde,0xaf,0xc3,0x17,0x51,0x01,0xfb,0x2e,0x54,0xa6,0x7f,0x8e,0xfb,0x7d,0x36,0x54,0xb0,0xbe,0x00,0xa5,0x1f,0x2a,0x51,0xa1,0x86,0x42,0x94,0xfa,0x6f,0xa0,0x42,0x0f,0x8a,0x51,0x1a,0xac,0x41,0x85,0x1f,0x1d,0x41,0xe9,0x47,0x3b,0x2a,0xec,0x28,0x41,0xe9,0xc8,0x3d,0xd4,0x88,0xd3,0x84,0xd2,0xe8,0x43,0x54,0xc4,0x75,0x06,0xa5,0x63,0x0e,0xd4,0x68,0x9b,0x15,0xa5,0xb1,0x16,0xd4,0x68,0x87,0x0d,0xa5,0xe3,0xed,0xa8,0xb1,0xae,0x2a,0x94,0x4e,0x76,0xa1,0x62,0xdd,0xd5,0x28,0x4d,0xb8,0x51,0x31,0x77,0x2d,0x4a,0xa7,0x7b,0x51,0xf1,0x37,0xf5,0x28,0xfd,0xfe,0x1e,0x15,0xef,0x6b,0x44,0xe9,0x8f,0x21,0xd4,0xf8,0xbb,0xc7,0x28,0xfd,0x19,0x44,0x4d,0x78,0x9c,0x28,0x9d,0x89,0xa2,0x26,0xbd,0xad,0x28,0xd5,0x38,0x2a,0x31,0xfc,0x02,0xa5,0x9a,0x40,0x25,0xfc,0x9d,0x28,0xd5,0x14,0x6a,0x2a,0xf4,0x12,0xa5,0x3a,0x83,0x4a,0x86,0x5f,0xa1,0x14,0xbe,0x64,0xe4,0x35,0x8a,0xef,0xef,0x41,0x65,0xfa,0x33,0xfd,0x99,0xfe,0x4c,0xff,0x5c,0xf5,0x1b,0xc6,0x2f,0xf5,0xb2,0x92,0x43,};

TEST(ImageLoader, Bmp) {
    ABuiltinFiles::load(AUI_PACKED_assettarget, sizeof(AUI_PACKED_assettarget));
    auto image = AImage::fromUrl(":target.bmp");
    ASSERT_TRUE(image != nullptr);
    ASSERT_EQ(image->getWidth(), 64);
    ASSERT_EQ(image->getHeight(), 64);
}
