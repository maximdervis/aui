﻿// AUI Framework - Declarative UI toolkit for modern C++17
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

#include "AFileOutputStream.h"

#include "AUI/Common/AString.h"
#include "AUI/Platform/ErrorToException.h"

AFileOutputStream::AFileOutputStream(AString path, bool append): mPath(std::move(path))
{
#if AUI_PLATFORM_WIN
	// КАК ЖЕ ЗАКОЛЕБАЛА ЭТА ВЕНДА
	_wfopen_s(&mFile, mPath.c_str(), append ? L"a+b" : L"wb");
#else
	mFile = fopen(mPath.toStdString().c_str(), append ? "a+b" : "wb");
#endif
	if (!mFile)
	{
        aui::impl::unix::lastErrorToException("AFileOutputStream: could not open {}"_format(mPath));
	}
}

AFileOutputStream::~AFileOutputStream()
{
    close();
}

void AFileOutputStream::write(const char* src, size_t size)
{
    assert(("file not open", mFile != nullptr));
    if (size == 0) return;
	while (size) {
        auto v = fwrite(src, 1, size, mFile);
        if (v == 0) {
            aui::impl::unix::lastErrorToException(mPath);
        }
        size -= v;
        src += v;
    }
}

void AFileOutputStream::close() {
    if (mFile) {
        fclose(mFile);
        mFile = nullptr;
    }
}
