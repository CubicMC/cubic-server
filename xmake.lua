set_project("cubic-server")

add_rules("mode.debug", "mode.release")

target("CubicServer")
    set_kind("binary")
    set_languages("cxx17")
    set_warnings("all")

    add_files("cubic-server/**.cpp")
    add_includedirs("cubic-server")
    add_headerfiles("cubic-server/**.hpp")
target_end()

-- Define the test dependency
add_requires("gtest", {configs = {main = true, gmock = false}})

-- Iterate over test files and create test targets
for _, file in ipairs(os.files("tests/test_*.cpp")) do
    local name = path.basename(file)
    target(name)
        set_kind("binary")
        add_packages("gtest")
        set_default(false)
        add_files(file)
        add_tests("default")
end
