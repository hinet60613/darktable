/*
    This file is part of darktable,
    copyright (c) 2016 Roman Lebedev.

    darktable is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    darktable is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with darktable.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <string.h>

// FIXME: in the future, we may want to also take DRIVER_VERSION into account
static const char *bad_opencl_drivers[] = {
  // clang-format off

  "beignet",
  "pocl",
  NULL

  // clang-format on
};

// 0 - ok
// else it is blacklisted
int dt_opencl_check_driver_blacklist(const char *device_version)
{
  for(int i = 0; bad_opencl_drivers[i]; i++)
  {
    // FIXME: cAsE?
    if(!strstr(device_version, bad_opencl_drivers[i])) continue;

    // oops, found in black list
    return 1;
  }

  // did not find in the black list, guess it's ok.
  return 0;
}

// modelines: These editor modelines have been set for all relevant files by tools/update_modelines.sh
// vim: shiftwidth=2 expandtab tabstop=2 cindent
// kate: tab-indents: off; indent-width 2; replace-tabs on; indent-mode cstyle; remove-trailing-spaces modified;
