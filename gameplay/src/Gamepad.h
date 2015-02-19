#ifndef GAMEPAD_H_
#define GAMEPAD_H_

#include "Vector2.h"

namespace gameplay
{

class Button;
class Container;
class Form;
class JoystickControl;
class Platform;

/**
 * Defines a gamepad interface for handling input from joysticks and buttons.
 *
 * A gamepad can be either physical or virtual. Most platform support up to 4
 * gamepad controllers connected simulataneously.
 */
class Gamepad
{
    friend class Platform;
    friend class Game;
    friend class Button;

public:
    
    /* --- 1. Tim added code start --- */
    
    // For describing the new game events I'm making
    enum ButtonEvent {
        BUTTON_PRESS,
        BUTTON_RELEASE,
    };
    /*
     enum AxisEvent {
     AXIS_DPAD,
     AXIS_LEFTJOYSTICK,
     AXIS_RIGHTJOYSTICK,
     AXIS_LEFTTRIGGER,
     AXIS_RIGHTTRIGGER
     };*/
    
    // Keycodes for external gamepads
    // I've cut it down to only expected gamepad ones
    enum {
        AKEYCODE_UNKNOWN         = 0,
        
        AKEYCODE_HOME            = 3,
        AKEYCODE_BACK            = 4,
        
        AKEYCODE_DPAD_UP         = 19,
        AKEYCODE_DPAD_DOWN       = 20,
        AKEYCODE_DPAD_LEFT       = 21,
        AKEYCODE_DPAD_RIGHT      = 22,
        AKEYCODE_DPAD_CENTER     = 23,
        AKEYCODE_VOLUME_UP       = 24,
        AKEYCODE_VOLUME_DOWN     = 25,
        
        AKEYCODE_MENU            = 82,
        
        // 3 media buttons on amazon
        AKEYCODE_MEDIA_PLAY_PAUSE= 85,
        AKEYCODE_MEDIA_REWIND    = 89,
        AKEYCODE_MEDIA_FAST_FORWARD = 90,
        
        AKEYCODE_BUTTON_A        = 96,
        AKEYCODE_BUTTON_B        = 97,
        AKEYCODE_BUTTON_C        = 98,
        AKEYCODE_BUTTON_X        = 99,
        AKEYCODE_BUTTON_Y        = 100,
        AKEYCODE_BUTTON_Z        = 101,
        AKEYCODE_BUTTON_L1       = 102,
        AKEYCODE_BUTTON_R1       = 103,
        AKEYCODE_BUTTON_L2       = 104,
        AKEYCODE_BUTTON_R2       = 105,
        AKEYCODE_BUTTON_THUMBL   = 106,
        AKEYCODE_BUTTON_THUMBR   = 107,
        AKEYCODE_BUTTON_START    = 108,
        AKEYCODE_BUTTON_SELECT   = 109,
        AKEYCODE_BUTTON_MODE     = 110,
        
        // these will be mapped to above
        AKEYCODE_BUTTON_1        = 188,
        AKEYCODE_BUTTON_2        = 189,
        AKEYCODE_BUTTON_3        = 190,
        AKEYCODE_BUTTON_4        = 191,
        AKEYCODE_BUTTON_5        = 192,
        AKEYCODE_BUTTON_6        = 193,
        AKEYCODE_BUTTON_7        = 194,
        AKEYCODE_BUTTON_8        = 195,
        AKEYCODE_BUTTON_9        = 196,
        AKEYCODE_BUTTON_10       = 197,
        AKEYCODE_BUTTON_11       = 198,
        AKEYCODE_BUTTON_12       = 199,
    };
    
    // --- moved to public by Tim
    GamepadHandle _handle;
    
    /* --- 1. Tim added code end   --- */
    
    

    /**
     *  Gamepad events.
     */
    enum GamepadEvent
    {
        CONNECTED_EVENT,
        DISCONNECTED_EVENT
    };

    /**
     * Gamepad buttons.
     */
    enum ButtonMapping
    {        
        BUTTON_A,
        BUTTON_B,
        BUTTON_X,
        BUTTON_Y,
        BUTTON_L1,
        BUTTON_L2,
        BUTTON_L3,
        BUTTON_R1,
        BUTTON_R2,
        BUTTON_R3,
        BUTTON_UP,
        BUTTON_DOWN,
        BUTTON_LEFT,
        BUTTON_RIGHT,
        BUTTON_MENU1,
        BUTTON_MENU2,
        BUTTON_MENU3
    };

    /**
     * Gets the number of buttons on this gamepad.
     *
     * @return The number of buttons on this gamepad.
     */
    unsigned int getButtonCount() const;

    /** 
     * Gets whether the given button is currently pressed down.
     *
     * @param button The enum of the button on the gamepad to get the state for.
     * @return Whether the button is currently pressed or not.
     */
    bool isButtonDown(ButtonMapping button) const;
    
    /**
     * Gets the number of joysticks on the gamepad.
     *
     * @return the number of joysticks on the gamepad.
     */
    unsigned int getJoystickCount() const;

    /**
     * Returns the specified joystick's value as a Vector2.
     *
     * @param joystickId The index of the joystick to get the value for.
     * @param outValues The current x-axis and y-axis values of the joystick.
     */
    void getJoystickValues(unsigned int joystickId, Vector2* outValues) const;

    /**
     * Returns the number of analog triggers (as opposed to digital shoulder buttons)
     * on this gamepad.
     *
     * @return The number of analog triggers on this gamepad.
     */
    unsigned int getTriggerCount() const;

    /**
     * Returns the value of an analog trigger on this gamepad.  This value will be a
     * number between 0 and 1, where 0 means the trigger is in its resting (unpressed)
     * state and 1 means the trigger has been completely pressed down.
     *
     * @param triggerId The trigger to query.
     * @return The value of the given trigger.
     */
    float getTriggerValue(unsigned int triggerId) const;

    /**
     * Get this gamepad's device/product name.
     *
     * @return This gamepad's device/product name.
     */
    const char* getName() const;

    /**
     * Returns whether the gamepad is currently represented with a UI form or not.
     *
     * @return true if the gamepad is currently represented by a UI form; false if the gamepad is
     *         not represented by a UI form.
     */
    bool isVirtual() const;

    /**
     * Gets the Form used to represent this gamepad.
     *
     * @return the Form used to represent this gamepad. NULL if the gamepad is not represented with a Form.
     */
    Form* getForm() const;

    /**
     * Updates the gamepad's state.  For a virtual gamepad, this results in calling update()
     * on the gamepad's form.  For physical gamepads, this polls the gamepad's state
     * at the platform level.  Either way, this should be called once a frame before
     * getting and using a gamepad's current state.
     *
     * @param elapsedTime The elapsed game time.
     */
    void update(float elapsedTime);

    /**
     * Draws the gamepad if it is based on a form and if the form is enabled.
     */
    void draw();

private:

    /**
     * Constructs a gamepad from the specified .form file.
     *
     * @param formPath The path the the .form file.
     */ 
    Gamepad(const char* formPath);

    /**
     * Constructs a physical gamepad.
     *
     * @param handle The gamepad handle
     * @param buttonCount the number of buttons on the gamepad. 
     * @param joystickCount the number of joysticks on the gamepad.
     * @param triggerCount the number of triggers on the gamepad.
     * @param name The product/device name.
     */
    Gamepad(GamepadHandle handle, unsigned int buttonCount, unsigned int joystickCount, unsigned int triggerCount, const char* name);

    /**
     * Copy constructor.
     */
    Gamepad(const Gamepad& copy);

    /** 
     * Destructor.
     */
    virtual ~Gamepad();

    static void updateInternal(float elapsedTime);

    static Gamepad* add(GamepadHandle handle, unsigned int buttonCount, unsigned int joystickCount, unsigned int triggerCount, const char* name);

    static Gamepad* add(const char* formPath);

    static void remove(GamepadHandle handle);

    static void remove(Gamepad* gamepad);

    static unsigned int getGamepadCount();

    static Gamepad* getGamepad(unsigned int index, bool preferPhysical);

    static Gamepad* getGamepad(GamepadHandle handle);

    static ButtonMapping getButtonMappingFromString(const char* string);

    void setButtons(unsigned int buttons);

    void setJoystickValue(unsigned int index, float x, float y);

    void setTriggerValue(unsigned int index, float value);
    
    void bindGamepadControls(Container* container);

    GamepadHandle _handle;
    unsigned int _buttonCount;
    unsigned int _joystickCount;
    unsigned int _triggerCount;
    std::string _name;
    Form* _form;
    JoystickControl* _uiJoysticks[2];
    Button* _uiButtons[20];
    unsigned int _buttons;
    Vector2 _joysticks[2];
    float _triggers[2];
};

}

#endif
