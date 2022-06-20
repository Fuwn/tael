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

#include <tael/context.hh>
#include <tatl/macros.h>

/* The dummy Tatl context to test using Tatl... Tatl-ception... but with Tael!
 */
tael::context dummy_context;

TATL_TEST(dummy_pass) { return 1; }
TATL_TEST(dummy_fail) { return 0; }
TATL_TEST(tael_context_total_works) {
  return TATL_IS(dummy_context.total(), 3);
}
TATL_TEST(tael_context_passed_works) {
  return TATL_IS(dummy_context.passed(), 2);
}
TATL_TEST(tael_context_failed_works) {
  return TATL_IS(dummy_context.failed(), 1);
}
TATL_TEST(tael_context_tag_works) {
  return std::string(dummy_context.tag()) == "hi";
}
TATL_TEST(tael_context_mute_works) {
  return TATL_IS(dummy_context.mute(), true);
}

int main() {
  /* Mute the output of the dummy Tael context */
  dummy_context.set_mute(true);
  /* Add a predictable tag to the dummy Tael context to test */
  dummy_context.set_tag("hi");
  /* Add predictable tests to the dummy Tatl context to test */
  dummy_context.add("dummy_pass", dummy_pass);
  dummy_context.add("dummy_pass 2", dummy_pass);
  dummy_context.add("dummy_fail", dummy_fail);
  dummy_context.run();

  /* Our "real" Tael context which tests our dummy Tael context */
  tael::context context("tests/tael/test.cc");

  context.add("tael_context_total", tael_context_total_works);
  context.add("tael_context_passed", tael_context_passed_works);
  context.add("tael_context_failed", tael_context_failed_works);
  context.add("tael_context_tag", tael_context_tag_works);
  context.add("tael_context_mute", tael_context_mute_works);
  context.finish();

  return context.exit_code();
}
