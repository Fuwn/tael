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

#include <iostream>

#include <tael/context.hh>

#include <tatl/context/set.h>

namespace tael {

context::context(const std::string &tag, bool mute) {
  tatl_new(&this->inner_context);
  tatl_context_set_mute(&this->inner_context, mute);

  if (!tag.empty()) {
    tatl_context_set_tag(&this->inner_context, tag.c_str());
  }
}

context::~context() { tatl_destroy(this->inner_context); }

std::size_t context::total() const { return this->inner_context._total; }

std::size_t context::passed() const { return this->inner_context._passed; }

std::size_t context::failed() const { return this->inner_context._failed; }

const char *context::tag() const { return this->inner_context._tag; }

bool context::mute() const { return this->inner_context._mute; }

int context::exit_code() const { return this->inner_context._exit_code; }

void context::set_mute(bool mute) { this->inner_context._mute = mute; }

void context::set_tag(const std::string &tag) {
  tatl_context_set_tag(&this->inner_context, tag.c_str());
}

void context::summary() { tatl_summary(this->inner_context); }

void context::add(const char *const tag, int (*test)()) {
  tatl_add(&this->inner_context, tag, test);
}

void context::run() { tatl_run(&this->inner_context); }

void context::finish() {
  this->run();

  if (!this->inner_context._mute) {
    std::cout << '\n';
  }

  this->summary();

  if (!this->inner_context._mute) {
    std::cout << '\n';
  }
}

} // namespace tael
