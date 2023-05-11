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
cubic_deps =        []

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
# set name and version
#=====================

cxxflags += ['-DPROGRAM_NAME="CubicServer"', '-DPROGRAM_VERSION="' + meson.project_version() + '"' ]

#=====================
# Manage dependencies.
#=====================

# pkgconfig is required for meson to work correctly.
# dependencies might not be found without it on linux.

thread = dependency('threads',   required: true)
gtkmm =  dependency('gtkmm-3.0', required: true)
curl =   dependency('libcurl', required: true)

yaml     = dependency('yaml-cpp',      required: false)
json     = dependency('nlohmann_json', required: false)
noise    = dependency('perlin_noise',  required: false)
argparse = dependency('argparse',      required: false)
crcpp    = dependency('CRCpp',         required: false)

if get_option('buildtype') == 'debug' and get_option('test')
  gtest = dependency('gtest', main: true, required: false)
  rapidcheck = dependency('rapidcheck', required: false)
endif

#===============================
# retrieve missing dependencies.
#===============================

cmake = import('cmake')

if not yaml.found()
  yaml_subproj = cmake.subproject('yaml-cpp')
  yaml = yaml_subproj.dependency('yaml-cpp')
endif

if not json.found()
  json = dependency('nlohmann_json')
endif

# we need to create a patch fot this one.
if not noise.found()
  noise = dependency('perlin_noise')
endif

if not argparse.found()
  argparse = dependency('argparse')
endif

if not crcpp.found()
  crcpp_subproj = cmake.subproject('crcpp')
  crcpp = crcpp_subproj.dependency('CRCpp')
endif

cubic_deps += [ thread, gtkmm, curl, yaml, json, noise, argparse, crcpp ] # need to add perlin

if get_option('buildtype') == 'debug' and get_option('test')
  if not gtest.found()
    gtest = dependency('gtest', main: true)
  endif

  if not rapidcheck.found()
    rapidcheck_subproj = cmake.subproject('rapidcheck')
    rapidcheck = rapidcheck_subproj.dependency('rapidcheck')
  endif
  cubic_deps += [ gtest, rapidcheck ]
endif

#============================
# Fetch internal dependencies
#============================

subdir('cubic-server')

#=================================
# TODO
#=================================

exe = executable('cubic_server',
  cubic_src,
  include_directories: cubic_include,
  dependencies : cubic_deps,
  cpp_args: cxxflags,
  link_args: ldflags,
  install : true)
