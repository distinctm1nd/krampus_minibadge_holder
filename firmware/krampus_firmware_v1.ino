#include <avr/io.h>
#include <util/delay.h>

#define EYE_TONGUE_LED_ARRAY 4    
#define NUM_EYE_TONGUE_LEDS 5       
#define BUTTON_PIN 1         
#define MINIBADGE_CLK_CTRL_H_PIN 3 
#define MINIBADGE_CLK_CTRL_L_PIN 2 

enum LedMode {
    KRAMPUS_NIGHT, 
    GREETINGS_FROM_KRAMPUS,   
    STEALING_YOUR_MINIBADGES,  
    FEAR_IS_PRICE_FOR_CHEER,    
    SNOWY_NIGHT,   
    DEADLY_NIGHT,
    KRAMPUS_IS_SANTA,
    ALL_IS_CALM, 
    SLAY_BELLS,
    IN_THE_SHADOWS
};

LedMode currentMode = SLAY_BELLS; // Set default mode

void krampusNightLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Red
            g = 0; 
            r = 200; 
            b = 0; 
            break;
        case 1: // Bright Red
            g = 0; 
            r = 255;
            b = 0; 
            break;
        case 2: // Light Brown
            g = 165; 
            r = 90; 
            b = 0; 
            break;
        case 3: // Dark Brown
            g = 75;  
            r = 40; 
            b = 0; 
            break;
        case 4: // Yellow
            g = 255; 
            r = 255; 
            b = 0; 
            break;
    }
}


void greetingsFromKrampusLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Red
            g = 0;
            r = 200;                        
            b = 0;             
            break;
        case 1: // Medium Red
            g = 0;
            r = 255;                        
            b = 0;             
            break;
        case 2: // Dark Red
            g = 0;
            r = 150;                        
            b = 0;             
            break;
        case 3: // Deep Red
            g = 0;
            r = 100;                        
            b = 0;             
            break;
        case 4: // Yellow
            g = 255; 
            r = 255;                     
            b = 0;             
            break;
    }
}


void fearIsPriceOfCheerLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Purple
            g = 128;
            r = 0;    
            b = 255;          
            break;
        case 1: // Dark Purple
            g = 75;
            r = 0;    
            b = 150;          
            break;
        case 2: // Light Blue
            g = 0;
            r = 0;    
            b = 200;          
            break;
        case 3: // Dark Blue
            g = 0;
            r = 0;    
            b = 100;          
            break;
        case 4: // Red
            g = 0;
            r = 255;    
            b = 0;            
            break;
    }
}


void stealingYourMinibadgesLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Green
            g = 200;
            r = 0;   
            b = 0;  
            break;
        case 1: // Medium Light Green
            g = 150; 
            r = 0;  
            b = 0;  
            break;
        case 2: // Medium Green
            g = 100; 
            r = 0;   
            b = 0;   
            break;
        case 3: // Dark Green
            g = 50;  
            r = 0;   
            b = 0;   
            break;
        case 4: // Yellow-Green
            g = 255;
            r = 255; 
            b = 0;  
            break;
    }
}


void snowyNightLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Purple
            g = 128; 
            r = 64;  
            b = 128; 
            break;
        case 1: // Dark Purple
            g = 0;   
            r = 0;   
            b = 255; 
            break;
        case 2: // Light Blue
            g = 0;   
            r = 0;  
            b = 200; 
            break;
        case 3: // Dark Blue
            g = 0;   
            r = 0;   
            b = 100; 
            break;
        case 4: // White
            g = 255; 
            r = 255; 
            b = 255; 
            break;
    }
}


void deadlyNightLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Bright Red
            g = 0; 
            r = 255; 
            b = 0; 
            break;
        case 1: // Medium Red
            g = 0; 
            r = 200; 
            b = 0; 
            break;
        case 2: // Dark Red
            g = 0; 
            r = 150; 
            b = 0; 
            break;
        case 3: // Deeper Red
            g = 0; 
            r = 100;
            b = 0; 
            break;
        case 4: // Dark Brown
            g = 10;  
            r = 40;  
            b = 0;  
            break;
    }
}


void krampusIsSantaLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 4) {
        case 0: // Light Orange
            g = 165; 
            r = 255; 
            b = 0; 
            break;  
        case 1: // Medium Orange
            g = 140; 
            r = 255; 
            b = 0; break;  
        case 2: // Dark Orange
            g = 100; 
            r = 200; 
            b = 0; break;  
        case 3: // White
            g = 255; 
            r = 255; 
            b = 255; 
            break; 
    }
}

void allIsCalmLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Red
            g = 0; 
            r = 255; 
            b = 0; 
            break;
        case 1: // Yellow
            g = 255; 
            r = 255; 
            b = 0; 
            break;
        case 2: // Orange
            g = 165; 
            r = 255; 
            b = 0; 
            break;
        case 3: // Green
            g = 0; 
            r = 255; 
            b = 0; 
            break;
        case 4: // Purple
            g = 128; 
            r = 0; 
            b = 128; 
            break;
    }
}

void slayBellsLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Red
            g = 0; 
            r = 255; 
            b = 0; 
            break;
        case 1: // Green
            g = 255; 
            r = 0; 
            b = 0; 
            break;
        case 2: // Blue
            g = 0; 
            r = 0; 
            b = 255; 
            break;
        case 3: // Orange
            g = 165; 
            r = 255; 
            b = 0; 
            break;
        case 4: // Purple
            g = 128; 
            r = 0; 
            b = 128; 
            break;
    }
}

void inTheShadowsLedMode(uint8_t index, uint8_t& g, uint8_t& r, uint8_t& b) {
    switch (index % 5) {
        case 0: // Light Blue
            g = 0; 
            r = 0; 
            b = 255; 
            break;
        case 1: // Medium Blue
            g = 0; 
            r = 0; 
            b = 200; 
            break;
        case 2: // Dark Blue
            g = 0; 
            r = 0; 
            b = 100; 
            break;
        case 3: // Deep Blue
            g = 0; 
            r = 0; 
            b = 50; 
            break;
        case 4: // White
            g = 255; 
            r = 255; 
            b = 255;
            break;
    }
}


void sendColor(uint8_t g, uint8_t r, uint8_t b, uint8_t ledPin) {
    sendByte(g, ledPin);
    sendByte(r, ledPin);
    sendByte(b, ledPin);
}

void sendByte(uint8_t byte, uint8_t ledPin) {
    for (int i = 0; i < 8; i++) {
        if (byte & (1 << (7 - i))) {
            PORTA.OUTSET = (1 << ledPin);
            _delay_us(0.4);
            PORTA.OUTCLR = (1 << ledPin);
            _delay_us(0.85); 
        } else {
            PORTA.OUTSET = (1 << ledPin);
            _delay_us(0.2); 
            PORTA.OUTCLR = (1 << ledPin);
            _delay_us(0.9); 
        }
    }
}

void colorWipe(uint8_t green, uint8_t red, uint8_t blue, uint8_t ledPin, uint8_t numLeds) {
    for (int i = 0; i < numLeds; i++) {
        sendColor(green, red, blue, ledPin); 
        _delay_us(500); 
    }
}

void setup() {
    // Set eye_led_array and letter_led_array as output
    PORTA.DIRSET =  (1 << EYE_TONGUE_LED_ARRAY);
    
    // Set button pin as input with pull-up resistor
    PORTA.DIRCLR = (1 << BUTTON_PIN);
    PORTA.OUTSET = (1 << BUTTON_PIN); 

    // Set minibadge clock pins as output
    PORTA.DIRSET = (1 << MINIBADGE_CLK_CTRL_H_PIN) | (1 << MINIBADGE_CLK_CTRL_L_PIN);
    
    // Ensure all LEDs are off at the start
    colorWipe(0, 0, 0, EYE_TONGUE_LED_ARRAY, NUM_EYE_TONGUE_LEDS);
    _delay_ms(100);
}

bool isButtonPressed() {
    return (PORTA.IN & (1 << BUTTON_PIN)) == 0;
}

void updateMinibadgeClock() {
    if (PORTA.IN & (1 << MINIBADGE_CLK_CTRL_H_PIN)) {
        PORTA.OUTCLR = (1 << MINIBADGE_CLK_CTRL_H_PIN);
        PORTA.OUTSET = (1 << MINIBADGE_CLK_CTRL_L_PIN); 
    } else {
        PORTA.OUTSET = (1 << MINIBADGE_CLK_CTRL_H_PIN); 
        PORTA.OUTCLR = (1 << MINIBADGE_CLK_CTRL_L_PIN); 
    }
}

void loop() {
    static uint32_t lastClockUpdate = 0;
    const uint32_t clockUpdateInterval = 1000; // 1 second
    static uint8_t ledIndex = 0;
    static uint32_t lastUpdateTime = 0;
    const uint32_t updateInterval = 200; 

    // Check if it's time to update the LED colors
    if (millis() - lastUpdateTime >= updateInterval) {
        lastUpdateTime = millis();

        uint8_t green, red, blue;

        // Update the color for the current LED based on the mode
        switch (currentMode) {
            case KRAMPUS_NIGHT:
                krampusNightLedMode(ledIndex, green, red, blue);
                break;
            case GREETINGS_FROM_KRAMPUS:
                greetingsFromKrampusLedMode(ledIndex, green, red, blue);
                break;
            case STEALING_YOUR_MINIBADGES:
                fearIsPriceOfCheerLedMode(ledIndex, green, red, blue);
                break;
            case FEAR_IS_PRICE_FOR_CHEER:
                stealingYourMinibadgesLedMode(ledIndex, green, red, blue);
                break;
            case SNOWY_NIGHT:
                snowyNightLedMode(ledIndex, green, red, blue);
                break;
            case DEADLY_NIGHT:
                deadlyNightLedMode(ledIndex, green, red, blue);
                break;
            case KRAMPUS_IS_SANTA: 
                krampusIsSantaLedMode(ledIndex, green, red, blue);
                break;
            case ALL_IS_CALM: 
                allIsCalmLedMode(ledIndex, green, red, blue);
                break;
            case SLAY_BELLS:
                slayBellsLedMode(ledIndex, green, red, blue);
                break;
            case IN_THE_SHADOWS: 
                inTheShadowsLedMode(ledIndex, green, red, blue);
                break;
        }

        // Light up the current LED
        sendColor(green, red, blue, EYE_TONGUE_LED_ARRAY); 
        _delay_us(500); 

       

        // Update all previous LEDs to maintain their color
        for (uint8_t i = 0; i < NUM_EYE_TONGUE_LEDS; i++) {
            uint8_t prevGreen, prevRed, prevBlue;
            switch (currentMode) {
                case KRAMPUS_NIGHT:
                    krampusNightLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case GREETINGS_FROM_KRAMPUS:
                    greetingsFromKrampusLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case STEALING_YOUR_MINIBADGES:
                    fearIsPriceOfCheerLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case FEAR_IS_PRICE_FOR_CHEER:
                    stealingYourMinibadgesLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case SNOWY_NIGHT:
                    snowyNightLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case DEADLY_NIGHT:
                    deadlyNightLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case KRAMPUS_IS_SANTA: 
                    krampusIsSantaLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case ALL_IS_CALM: 
                    allIsCalmLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case SLAY_BELLS: 
                    slayBellsLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
                case IN_THE_SHADOWS: 
                    inTheShadowsLedMode(((i + ledIndex) * 256 / NUM_EYE_TONGUE_LEDS) % 256, prevGreen, prevRed, prevBlue);
                    break;
            }
            sendColor(prevGreen, prevRed, prevBlue, EYE_TONGUE_LED_ARRAY); 
        }

        // Update LED index for the next iteration
        ledIndex = (ledIndex + 1) % NUM_EYE_TONGUE_LEDS;
    }

    // Button logic for mode change
    if (isButtonPressed()) {
        currentMode = static_cast<LedMode>((currentMode + 1) % 10); 
        _delay_ms(300); 
    }

    // Re-check the minibadge clock update
    if (millis() - lastClockUpdate >= clockUpdateInterval) {
        updateMinibadgeClock();
        lastClockUpdate = millis();
    }
}
