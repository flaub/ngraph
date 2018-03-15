# ******************************************************************************
# Copyright 2017-2018 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ******************************************************************************

set(FILE_NAME ${CMAKE_BINARY_DIR}/include/nlohmann/detail/macro_scope.hpp)
file(READ ${FILE_NAME} FILE_CONTENTS)
string(REPLACE
  "#if (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) < 40900"
  "#if (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) < 40805"
  REWRITTEN_FILE
  "${FILE_CONTENTS}"
)
file(WRITE ${FILE_NAME} "${REWRITTEN_FILE}")
message(STATUS "json library gcc minimum version number patched")
