project('cubic-server', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

#======================
# variables declaration
#======================

cxxflags =           []
ldflags  =           []
cubic_include =      []
cubic_src =          []
cubic_deps =         []
cubic_test_deps =    []
cubic_test_include = []
cubic_test_src =     []

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
boost =  dependency('boost', modules : ['system', 'container'], required: false)

json     = dependency('nlohmann_json', required: true, default_options: ['warning_level=0'])
noise    = dependency('perlin_noise',  required: true, default_options: ['warning_level=0'])
argparse = dependency('argparse',      required: true, default_options: ['warning_level=0'])
spdlog   = dependency('spdlog',        required: true, default_options: ['warning_level=0'])

yaml     = dependency('yaml-cpp',      required: false, default_options: ['warning_level=0'])
crcpp    = dependency('CRCpp',         required: false, default_options: ['warning_level=0'])
mbedtls  = dependency('mbedtls',       required: false, default_options: ['warning_level=0'])

if get_option('buildtype') == 'debug' and get_option('test')
  gtest = dependency('gtest', main: true, required: false)
  rapidcheck = dependency('rapidcheck', required: false)
endif

#===============================
# retrieve missing dependencies.
#===============================

cmake = import('cmake')

if not mbedtls.found()
  mbedtls_subproj = cmake.subproject('mbedtls')
  mbedtls = mbedtls_subproj.dependency('mbedtls')
endif

if not boost.found()
  boost_subproj = cmake.subproject('boost')
  boost = boost_subproj.dependency('Boost')
endif

if not yaml.found()
  yaml_subproj = cmake.subproject('yaml-cpp')
  yaml = yaml_subproj.dependency('yaml-cpp')
endif

if not crcpp.found()
  crcpp_subproj = cmake.subproject('crcpp')
  crcpp = crcpp_subproj.dependency('CRCpp')
endif

cubic_deps += [ thread, gtkmm, curl, boost, yaml, json, noise, argparse, spdlog, crcpp, mbedtls ] # need to add perlin

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
