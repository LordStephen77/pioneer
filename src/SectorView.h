#ifndef _SECTORVIEW_H
#define _SECTORVIEW_H

#include "libs.h"
#include "gui/Gui.h"
#include "View.h"
#include <vector>
#include <string>
#include "View.h"
#include "Sector.h"
#include "SystemPath.h"

class SectorView: public View {
public:
	SectorView();
	virtual ~SectorView();
	virtual void Update();
	virtual void Draw3D();
	SystemPath GetSelectedSystem() const { return m_selected; }
	void GotoSystem(const SystemPath &path);
	void WarpToSystem(const SystemPath &path);
	virtual void Save(Serializer::Writer &wr);
	virtual void Load(Serializer::Reader &rd);
	virtual void OnSwitchTo();
private:
	void DrawSector(int x, int y, int z);
	void PutClickableLabel(std::string &text, const SystemPath &path);
	void OnClickSystem(const SystemPath &path);
	void MouseButtonDown(int button, int x, int y);
	Sector* GetCached(int sectorX, int sectorY, int sectorZ);
	void ShrinkCache();

	float m_zoom;

	bool m_firstTime;
	SystemPath m_selected;

	vector3f m_pos;
	vector3f m_posMovingTo;
	float m_rot_x, m_rot_z;
	Gui::Label *m_infoLabel;
	Gui::ImageButton *m_zoomInButton;
	Gui::ImageButton *m_zoomOutButton;
	Gui::ImageButton *m_galaxyButton;
	GLuint m_gluDiskDlist;
	
	Gui::Label *m_systemName;
	Gui::Label *m_distance;
	Gui::Label *m_starType;
	Gui::Label *m_shortDesc;
	Gui::LabelSet *m_clickableLabels;
	sigc::connection m_onMouseButtonDown;

	std::map<SystemPath,Sector*> m_sectorCache;
};

#endif /* _SECTORVIEW_H */
