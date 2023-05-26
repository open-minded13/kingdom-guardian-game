#include "Slider.hpp"
#include <algorithm>

Slider::Slider(float x, float y, float w, float h) :
	ImageButton("stage-select/slider.png", "stage-select/slider-blue.png", x, y),
	Bar("stage-select/bar.png", x, y, w, h),
	End1("stage-select/end.png", x, y + h / 2, 0, 0, 0.5, 0.5),
	End2("stage-select/end.png", x + w, y + h / 2, 0, 0, 0.5, 0.5) {
	Position.x += w;
	Position.y += h / 2;
	Anchor = Engine::Point(0.5, 0.5);
}

void Slider::Draw() const {
	Bar.Draw();
	End1.Draw();
	End2.Draw();
	ImageButton::Draw();
	return;
}

void Slider::SetOnValueChangedCallback(std::function<void(float value)> onValueChangedCallback) {
	OnValueChangedCallback = onValueChangedCallback;
}

void Slider::SetValue(float value) {
    if(value != this->value){
        this->value = value;
        this->Position.x = Bar.Position.x + value*Bar.Size.Magnitude();
        if (OnValueChangedCallback){
            OnValueChangedCallback((float) value);
	   	    ImageButton("stage-select/slider.png", "stage-select/slider-blue.png", value, Position.y);
		}
	}
}

void Slider::OnMouseDown(int button, int mx, int my) {
	if ((button & 1) && mouseIn && Enabled) {
        Down = true;
		if (OnClickCallback)
			OnClickCallback();
	}
}

void Slider::OnMouseUp(int button, int mx, int my) {
	if((button & 1) && Enabled){
	    Down = false;
	}
}

void Slider::OnMouseMove(int mx, int my) {
    ImageButton:: OnMouseMove(mx,my);
    float value;
    if(Down == true){
        if(mx > Bar.Position.x+Bar.Size.Magnitude()){
            value = 1;
            SetValue(value);
            return;
        }
        else if(mx < Bar.Position.x){
            value = 0;
            SetValue(value);
            return;
        }
        else{
            value = (mx-Bar.Position.x) / Bar.Size.Magnitude();
            SetValue(value);
            return;
        }
    }
}
