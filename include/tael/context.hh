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

#ifndef TAEL_CONTEXT
#define TAEL_CONTEXT

#include <string>

#include <tatl/context.h>
#include <tatl/context/set.h>

namespace tael {

// Hold the tests that a Tael should complete along with data about the Tael
// context
class context {
private:
  tatl_context inner_context;

public:
  // Initialise a Tael context with safe defaults; and optionally, with a tag
  // and mute state
  explicit context(const std::string & = "", bool = false);
  ~context();
  // Get the Tael context's total number of tests
  std::size_t total() const;
  // Get the Tael context's total number of passing tests
  std::size_t passed() const;
  // Get the Tael context's total number of failing tests
  std::size_t failed() const;
  // Get the Tael context's tag
  const char *tag() const;
  // Get the Tael context's mute status
  bool mute() const;
  // Get the Tael context's exit code
  int exit_code() const;
  // Set the Tael context's mute status
  //
  // Muting a Tael context disables any output that the context may produce.
  void set_mute(bool);
  // Set the Tael context's tag
  void set_tag(const std::string &);
  // Summarise the Tael context's test results
  //
  // Called automatically by finish
  void summary();
  // Add a test to the Tael context's test queue
  void add(const char *, int (*)());
  // Run all tests within the Tael context's test queue
  //
  // Called automatically by finish
  void run();
  // A comprehensive collection of tasks that calls many of the "finishing" Tael
  // operations
  //
  // Calls run and summary---in that order
  void finish();
};

} // namespace tael

#endif // TAEL_CONTEXT
