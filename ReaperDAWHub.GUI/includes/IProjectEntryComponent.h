#pragma once
__interface IProjectEntryComponent : Component
{
public:
	void resized() override;
	void paint(Graphics & g) override;
	void mouseEnter(const MouseEvent &) override;

};