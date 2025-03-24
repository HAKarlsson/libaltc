project('libserio', 'c', version : '1.0')
subdir('src')
incdirs = include_directories('include')
c_args = ['-ffat-lto-objects']
link_args = ['-ffat-lto-objects']
lib = static_library('serio', sources, c_args : c_args, link_args : link_args, include_directories : incdirs)
dep = declare_dependency(link_with : lib, include_directories : incdirs)
