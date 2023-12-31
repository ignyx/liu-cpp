// pending header file
#include "catch.hpp"
#include "list.h"
#include <sstream>

TEST_CASE("List : Initialize list object") {
  List list = List();

  CHECK(list.find_value_with_rank(5) == 0);
  CHECK(list.find_value_with_rank(0) == 0);
  CHECK(list.size() == 0);
  CHECK(list.is_empty());
}

TEST_CASE("List : Initialize list object with empty initializer_list") {
  List list{};

  CHECK(list.find_value_with_rank(5) == 0);
  CHECK(list.find_value_with_rank(0) == 0);
  CHECK(list.size() == 0);
  CHECK(list.is_empty());
}

TEST_CASE("List : Initialize list object with non-empty initializer_list") {
  List list{1};

  CHECK(list.find_value_with_rank(5) == 0);
  CHECK(list.find_value_with_rank(0) == 1);
  CHECK(list.size() == 1);
  CHECK_FALSE(list.is_empty());
}

TEST_CASE("List : Initialize list object with multiple values") {
  List list{3, 1, -43};

  CHECK(list.find_value_with_rank(0) == -43);
  CHECK(list.find_value_with_rank(1) == 1);
  CHECK(list.find_value_with_rank(2) == 3);
  CHECK(list.find_value_with_rank(3) == 0);
  CHECK(list.size() == 3);
  CHECK_FALSE(list.is_empty());
}

TEST_CASE("List : copy constructor with empty list") {
  List list{};
  List new_list{list};

  CHECK(new_list.find_value_with_rank(5) == 0);
  CHECK(new_list.find_value_with_rank(0) == 0);
  CHECK(new_list.size() == 0);
  CHECK(new_list.is_empty());
}

TEST_CASE("List : copy constructor with list of length 1 ") {
  List list{1};
  List new_list{list};

  CHECK(new_list.find_value_with_rank(1) == 0);
  CHECK(new_list.find_value_with_rank(0) == 1);
  CHECK(new_list.size() == 1);
  CHECK_FALSE(new_list.is_empty());
}

TEST_CASE("List : copy constructor with list of length 3") {
  List list{3, 1, -43};
  List new_list{list};

  CHECK(new_list.find_value_with_rank(0) == -43);
  CHECK(new_list.find_value_with_rank(1) == 1);
  CHECK(new_list.find_value_with_rank(2) == 3);
  CHECK(new_list.find_value_with_rank(3) == 0);
  CHECK(new_list.size() == 3);
  CHECK_FALSE(new_list.is_empty());
}

TEST_CASE("List : copy constructor with list of length 5") {
  List list{3, 1, -43, 0, 0};
  List new_list{list};

  CHECK(new_list.find_value_with_rank(0) == -43);
  CHECK(new_list.find_value_with_rank(1) == 0);
  CHECK(new_list.find_value_with_rank(2) == 0);
  CHECK(new_list.find_value_with_rank(3) == 1);
  CHECK(new_list.find_value_with_rank(4) == 3);
  CHECK(new_list.size() == 5);
  CHECK_FALSE(new_list.is_empty());
}

TEST_CASE("List : acess value with out-of-bounds rank") {
  List list{3, 1, -43, 0, 0};

  CHECK(list.find_value_with_rank(-1) == 0);
  CHECK(list.find_value_with_rank(5) == 0);
}

TEST_CASE("List : acess ranks with values") {
  List list{3, 1, -43, 0, 0};

  CHECK(list.find_rank_with_value(-43) == 0);
  CHECK(list.find_rank_with_value(0) == 1);
  CHECK(list.find_rank_with_value(1) == 3);
  CHECK(list.find_rank_with_value(3) == 4);
  CHECK(list.find_rank_with_value(-44) == -1);
  CHECK(list.find_rank_with_value(99) == -1);
}

TEST_CASE("List : copy operator") {
  List list_a{3, 1, -43, 0, 0};
  List list_b{5};

  list_a = list_b;

  CHECK(list_a.find_rank_with_value(-43) == -1);
  CHECK(list_a.find_rank_with_value(0) == -1);
  CHECK(list_a.find_rank_with_value(1) == -1);
  CHECK(list_a.find_rank_with_value(3) == -1);

  CHECK(list_b.find_rank_with_value(5) == 0);
  CHECK(list_a.find_rank_with_value(5) == 0);

  list_b.insert(3);
  CHECK(list_b.find_rank_with_value(3) == 0);
  CHECK(list_b.find_rank_with_value(5) == 1);
  CHECK(list_a.find_rank_with_value(3) == -1);
}

TEST_CASE("List : delete element with rank") {
  List list_a{-1, 0, 0, 1, 2};

  CHECK(list_a.find_value_with_rank(0) == -1);
  CHECK(list_a.find_value_with_rank(1) == 0);
  CHECK(list_a.find_value_with_rank(2) == 0);
  CHECK(list_a.find_value_with_rank(3) == 1);
  CHECK(list_a.find_value_with_rank(4) == 2);
  CHECK(list_a.size() == 5);

  list_a.delete_element_with_rank(0);

  CHECK(list_a.find_value_with_rank(0) == 0);
  CHECK(list_a.find_value_with_rank(1) == 0);
  CHECK(list_a.find_value_with_rank(2) == 1);
  CHECK(list_a.find_value_with_rank(3) == 2);
  CHECK(list_a.size() == 4);

  list_a.delete_element_with_rank(1);

  CHECK(list_a.find_value_with_rank(0) == 0);
  CHECK(list_a.find_value_with_rank(1) == 1);
  CHECK(list_a.find_value_with_rank(2) == 2);
  CHECK(list_a.size() == 3);

  list_a.delete_element_with_rank(2);

  CHECK(list_a.find_value_with_rank(0) == 0);
  CHECK(list_a.find_value_with_rank(1) == 1);
  CHECK(list_a.size() == 2);

  list_a.delete_element_with_rank(2);
  list_a.delete_element_with_rank(-1);

  CHECK(list_a.find_value_with_rank(0) == 0);
  CHECK(list_a.find_value_with_rank(1) == 1);
  CHECK(list_a.size() == 2);

  List list_b{};

  CHECK(list_b.size() == 0);
  list_b.delete_element_with_rank(0);
  list_b.delete_element_with_rank(1);
  list_b.delete_element_with_rank(-1);
}

TEST_CASE("List : delete element with values") {
  List list_a{-1, 0, 0, 1, 2};

  CHECK(list_a.find_value_with_rank(0) == -1);
  CHECK(list_a.find_value_with_rank(1) == 0);
  CHECK(list_a.find_value_with_rank(2) == 0);
  CHECK(list_a.find_value_with_rank(3) == 1);
  CHECK(list_a.find_value_with_rank(4) == 2);
  CHECK(list_a.size() == 5);

  list_a.delete_element_with_value(-1);

  CHECK(list_a.find_value_with_rank(0) == 0);
  CHECK(list_a.find_value_with_rank(1) == 0);
  CHECK(list_a.find_value_with_rank(2) == 1);
  CHECK(list_a.find_value_with_rank(3) == 2);
  CHECK(list_a.size() == 4);

  list_a.delete_element_with_value(0);

  CHECK(list_a.find_value_with_rank(0) == 0);
  CHECK(list_a.find_value_with_rank(1) == 1);
  CHECK(list_a.find_value_with_rank(2) == 2);
  CHECK(list_a.size() == 3);

  list_a.delete_element_with_value(2);

  CHECK(list_a.find_value_with_rank(0) == 0);
  CHECK(list_a.find_value_with_rank(1) == 1);
  CHECK(list_a.size() == 2);

  list_a.delete_element_with_value(2);
  list_a.delete_element_with_value(-5);

  CHECK(list_a.find_value_with_rank(0) == 0);
  CHECK(list_a.find_value_with_rank(1) == 1);
  CHECK(list_a.size() == 2);
}

TEST_CASE("List : move operator") {
  List list_a{3, 1, -43, 0, 0};
  List list_b{5};

  CHECK(list_a.size() == 5);
  CHECK(list_b.size() == 1);

  list_a = std::move(list_b); // move assignment

  CHECK(list_a.size() == 1);
  CHECK(list_b.size() == 0);
  CHECK(list_a.find_value_with_rank(0) == 5);

  list_a = std::move(list_b); // move assignment

  CHECK(list_a.size() == 0);
  CHECK(list_b.size() == 0);
  CHECK(list_a.find_value_with_rank(0) == 0);
}

TEST_CASE("List : move constructor") {
  List list_a{3, 1, -43, 0, 0};

  CHECK(list_a.size() == 5);

  List list_b{std::move(list_a)}; // move constructor

  CHECK(list_a.size() == 0);
  CHECK(list_b.size() == 5);
  CHECK(list_b.find_value_with_rank(0) == -43);
  CHECK(list_b.find_value_with_rank(1) == 0);
  CHECK(list_b.find_value_with_rank(4) == 3);
}

TEST_CASE("List : display non-empty list") {
  List list_a{3, 1, -43, 0, 0};

  CHECK(list_a.to_string() == "-43 0 0 1 3");
}

TEST_CASE("List : display empty list") {
  List list_a{};

  CHECK(list_a.to_string() == "");
}
