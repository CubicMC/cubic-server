project('cubic-server', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

#======================
# variables declaration
#======================

cxxflags =          []
ldflags  =          []
cubic_include =     []
cubic_src =         []

#=================================
# use libc++ on clang if installed
#=================================

if get_option('libcpp_clang')
    compiler = meson.get_compiler('cpp')
    if compiler.get_id() == 'clang'
        cxxflags += ['-stdlib=libc++']
        ldflags +=  ['-stdlib=libc++']
    else
        warning('Clang only option ignored because used on compiler ' + compiler.get_id())
    endif
endif

#=====================
# Manage dependencies.
#=====================

# pkgconfig is required for meson to work correctly.
# dependencies might not be found without it on linux.

thread = dependency('threads', required: false)
gtkmm =  dependency('gtkmm-3.0',   required: false)

yaml     = dependency('yaml-cpp',      required: false)
json     = dependency('nlohmann_json', required: false)
noise    = dependency('perlin_noise',  required: false)
argparse = dependency('argparse',      required: false)
crcpp    = dependency('CRCpp',         required: false)

if get_option('buildtype') == 'debug' and get_option('test')
  gtest = dependency('gtest', main: true, required: false)
  rapidcheck = dependency('rapidcheck', required: false)
endif

if get_option('download_missing')
  
endif

#=================================
# TODO
#=================================

exe = executable('cubic_server',
  install : true)
