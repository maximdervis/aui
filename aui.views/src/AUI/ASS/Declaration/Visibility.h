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

#pragma once

#include "IDeclaration.h"
#include <AUI/Enum/Visibility.h>

namespace ass::decl {
    template<>
    struct API_AUI_VIEWS Declaration<Visibility>: IDeclarationBase {
    private:
        Visibility mInfo;

    public:
        Declaration(const Visibility& visibility) : mInfo(visibility) {

        }

        void applyFor(AView* view) override;

        [[nodiscard]]
        const auto& value() const noexcept {
            return mInfo;
        }
    };
}