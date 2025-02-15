#ifndef ENGINEERING_SCREEN_H
#define ENGINEERING_SCREEN_H

#include "gui/gui2_overlay.h"
#include "shipTemplate.h"
#include "playerInfo.h"

class GuiSelfDestructButton;
class GuiKeyValueDisplay;
class GuiLabel;
class GuiSlider;
class GuiAutoLayout;
class GuiImage;
class GuiArrow;
class GuiToggleButton;
class GuiProgressbar;
class GuiProgressSlider;

class EngineeringScreen : public GuiOverlay
{
private:
    GuiOverlay* background_crosses;

    GuiKeyValueDisplay* energy_display;
    GuiKeyValueDisplay* hull_display;
    GuiKeyValueDisplay* front_shield_display;
    GuiKeyValueDisplay* rear_shield_display;
    GuiKeyValueDisplay* coolant_display;
    GuiSelfDestructButton* self_destruct_button;
    GuiLabel* power_label;
    GuiSlider* power_slider;
    GuiLabel* coolant_label;
    GuiSlider* coolant_slider;

    class SystemRow
    {
    public:
        GuiAutoLayout* layout;
        GuiToggleButton* button;
        GuiProgressbar* damage_bar;
        GuiImage* damage_icon;
        GuiProgressbar* health_max_bar;
        GuiLabel* damage_label;
        GuiProgressbar* heat_bar;
        GuiArrow* heat_arrow;
        GuiImage* heat_icon;
        GuiProgressSlider* power_bar;
        GuiProgressSlider* coolant_bar;
    };
    std::vector<SystemRow> system_rows;
    GuiAutoLayout* system_effects_container;
    std::vector<GuiKeyValueDisplay*> system_effects;
    unsigned int system_effects_index;
    ESystem selected_system;

    float previous_energy_measurement;
    float previous_energy_level;
    float average_energy_delta;

    void addSystemEffect(string key, string value);
    void selectSystem(ESystem system);

    string toNearbyIntString(float value);
public:
    EngineeringScreen(GuiContainer* owner, ECrewPosition crew_position=engineering);

    virtual void onDraw(sp::RenderTarget& target) override;
    virtual void onHotkey(const HotkeyResult& key) override;
    virtual bool onJoystickAxis(const AxisAction& axisAction) override;
};

#endif//ENGINEERING_SCREEN_H
