/*
 * Copyright (c) 2015 Enrico M. Crisostomo
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "win_paths.hpp"
#include <windows.h>
#include "../libfswatch_exception.hpp"
#include "../../gettext_defs.h"

using namespace std;

namespace fsw
{
  namespace win_paths
  {
    wstring posix_to_win_w(string path)
    {
       int pathlen = (int)path.length() + 1;
       int buflen = MultiByteToWideChar(CP_ACP, 0, path.c_str(), pathlen, 0, 0);
       wchar_t* buf = new wchar_t[buflen];
       MultiByteToWideChar(CP_ACP, 0, path.c_str(), pathlen, buf, buflen);
       std::wstring result(buf);
       delete[] buf;
       return result;
    }

    string win_w_to_posix(wstring path)
    {
       int pathlen = (int)path.length() + 1;
       int buflen = WideCharToMultiByte(CP_ACP, 0, path.c_str(), pathlen, 0, 0, 0, 0);
       char* buf = new char[buflen];
       WideCharToMultiByte(CP_ACP, 0, path.c_str(), pathlen, buf, buflen, 0, 0);
       std::string result(buf);
       delete[] buf;
       return result;
    }
  }
}
