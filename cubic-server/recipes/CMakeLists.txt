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
    recipes.tar.gz
    ${CMAKE_BINARY_DIR}
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)
file(ARCHIVE_EXTRACT INPUT ${CMAKE_BINARY_DIR}/recipes.tar.gz DESTINATION ${CMAKE_BINARY_DIR}/assets)
