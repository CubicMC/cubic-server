target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    Recipes.cpp
    Recipes.hpp
    Blasting.cpp
    Blasting.hpp
    CampfireCooking.cpp
    CampfireCooking.hpp
    CraftingShaped.cpp
    CraftingShaped.hpp
    CraftingShapeless.cpp
    CraftingShapeless.hpp
    Smelting.cpp
    Smelting.hpp
    Smithing.cpp
    Smithing.hpp
    Smoking.cpp
    Smoking.hpp
    SpecialArmorDye.cpp
    SpecialArmorDye.hpp
    SpecialBannerDuplicate.cpp
    SpecialBannerDuplicate.hpp
    SpecialBookCloning.cpp
    SpecialBookCloning.hpp
    SpecialFireworkRocket.cpp
    SpecialFireworkRocket.hpp
    SpecialFireworkStar.cpp
    SpecialFireworkStar.hpp
    SpecialFireworkStarFade.cpp
    SpecialFireworkStarFade.hpp
    SpecialMapCloning.cpp
    SpecialMapCloning.hpp
    SpecialMapExtending.cpp
    SpecialMapExtending.hpp
    SpecialRepairItem.cpp
    SpecialRepairItem.hpp
    SpecialShieldDecoration.cpp
    SpecialShieldDecoration.hpp
    SpecialShulkerboxColoring.cpp
    SpecialShulkerboxColoring.hpp
    SpecialSuspiciousStew.cpp
    SpecialSuspiciousStew.hpp
    SpecialTippedArrow.cpp
    SpecialTippedArrow.hpp
    StoneCutting.cpp
    StoneCutting.hpp
)

download_and_check_file(
    "https://cdn.cubic-mc.com/${MINECRAFT_VERSION}/recipes.tar.gz"
    "${CMAKE_BINARY_DIR}/recipes.tar.gz"
    ${CMAKE_BINARY_DIR}
)

execute_process(
    COMMAND tar xzf ${CMAKE_BINARY_DIR}/recipes.tar.gz
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND_ERROR_IS_FATAL ANY
)

execute_process(
    COMMAND mkdir -p assets
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND_ERROR_IS_FATAL ANY
)

execute_process(
    COMMAND mv -n ${CMAKE_BINARY_DIR}/recipes ${CMAKE_BINARY_DIR}/assets/recipes
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

execute_process(
    COMMAND rm -r ${CMAKE_BINARY_DIR}/recipes
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
