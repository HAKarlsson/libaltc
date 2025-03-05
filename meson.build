project('libserio', 'c', version : '1.0')

subdir('src')
incdirs = include_directories('include')

libserio = static_library(
  'serio',
  sources,
  include_directories : incdirs)

libserio_dep = declare_dependency(
  link_with : libserio,
  include_directories : incdirs)
