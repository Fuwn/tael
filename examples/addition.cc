/*
 * This file is part of Tatl <https://github.com/Fuwn/tatl>.
 * Copyright (C) 2022-2022 Fuwn <contact@fuwn.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2022-2022 Fuwn <contact@fuwn.me>
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include <tael/tael.hh>
#include <tael/tatl.hh>

namespace addition {

int add(int, int);
int dummy();
int add_works();
int dummy_long();
int dummy_longer();
int should_fail();

} // namespace addition

int main() {
  tael::context context("examples/addition.cc");

  context.add("dummy", addition::dummy);
  context.add("add works", addition::add_works);
  context.add("dummy long", addition::dummy_long);
#ifdef _MSC_VER
  context.add("dummy longer", addition::dummy_longer);
#endif
  context.add("should fail", addition::should_fail);
  context.finish();

  return 0;
}

namespace addition {

int add(int a, int b) { return a + b; }

int dummy() { return 1; }

int add_works() { return TATL_IS(add(1, 2), 3); }

int dummy_long() {
  for (int i = 0; i < 100000000; ++i) {
  }

  return 1;
}

int dummy_longer() {
  for (int i = 0; i < 1000000000; ++i) {
  }

  return 1;
}

int should_fail() { return TATL_IS(1, 2); }

} // namespace addition
