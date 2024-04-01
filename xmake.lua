set_project("ige")

add_rules("mode.debug", "mode.release")

target("CubicServer")
    set_kind("binary")
    set_languages("cxx17")
    set_warnings("all")

    add_files("cubic-server/**.cpp")
    add_includedirs("cubic-server")
    add_headerfiles("cubic-server/**.hpp")
