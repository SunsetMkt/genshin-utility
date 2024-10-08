#include <sdk.hpp>

#include <windows.h>

void sdk::initialize_genshin_impact_global() {
  auto mod = (unsigned long long)(GetModuleHandleA(nullptr));

  sdk::set_field_of_view = mod + 0x1136f30;

  sdk::set_target_frame_rate = mod + 0x1339720;
  sdk::quit = mod + 0x113b3d0;

  sdk::set_vsync_count = mod + 0xa50430;

  sdk::set_fog = mod + 0xa4f4e0;

  sdk::game_t::set(sdk::game_t::genshin_impact);
}

void sdk::initialize_genshin_impact_chinese() {
  auto mod = (unsigned long long)(GetModuleHandleA(nullptr));

  sdk::set_field_of_view = mod + 0x1136d30;

  sdk::set_target_frame_rate = mod + 0x1339520;
  sdk::quit = mod + 0x113b1d0;

  sdk::set_vsync_count = mod + 0xa50230;

  sdk::set_fog = mod + 0xa4f2e0;

  sdk::game_t::set(sdk::game_t::genshin_impact);
}

void sdk::initialize_star_rail() {
  auto game_assembly = (unsigned long long)(GetModuleHandleA("GameAssembly.dll"));

  sdk::set_field_of_view = game_assembly + 0x65b8110;

  sdk::set_target_frame_rate = game_assembly + 0x6870da0;
  sdk::quit = game_assembly + 0x68708a0;

  sdk::set_vsync_count = game_assembly + 0x696dc50;

  sdk::enter = game_assembly + 0x7609fc0;
  sdk::leave = game_assembly + 0x760cb50;

  sdk::game_t::set(sdk::game_t::star_rail);
}

void sdk::initialize() {
  if (GetModuleHandleA("StarRail.exe"))
    sdk::initialize_star_rail();
  else if (GetModuleHandleA("GenshinImpact.exe"))
    sdk::initialize_genshin_impact_global();
  else
    sdk::initialize_genshin_impact_chinese();
}
