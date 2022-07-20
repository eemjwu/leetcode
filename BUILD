load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "common_tool",
    hdrs = ["common_tool.h"],
)

cc_library(
    name = "leetcode",
    hdrs = ["leetcode.h"],
    srcs = ["leetcode.cc"],
    deps = [
        ":common_tool",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":leetcode",
    ],
)