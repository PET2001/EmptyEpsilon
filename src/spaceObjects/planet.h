#ifndef PLANET_H
#define PLANET_H

#include "nebula.h"
#include "spaceObject.h"
#include "pathPlanner.h"

class Planet : public SpaceObject, public Updatable
{
public:
    Planet();

#if FEATURE_3D_RENDERING
    virtual void draw3D() override;
    virtual void draw3DTransparent() override;
#endif//FEATURE_3D_RENDERING
    virtual void drawOnRadar(sp::RenderTarget& renderer, glm::vec2 position, float scale, float rotation, bool long_range) override;
    virtual void drawOnGMRadar(sp::RenderTarget& renderer, glm::vec2 position, float scale, float rotation, bool long_range) override;
    virtual void update(float delta) override;
    virtual void collide(Collisionable* target, float force) override;
    virtual bool canHideInNebula()  override { return false; }

    float getPlanetRadius();
    float getCollisionSize();

    void setPlanetAtmosphereColor(float r, float g, float b);
    void setPlanetAtmosphereTexture(string texture_name);
    void setPlanetSurfaceTexture(string texture_name);
    void setPlanetCloudTexture(string texture_name);
    void setPlanetRadius(float size);
    void setPlanetCloudRadius(float size);
    void setDistanceFromMovementPlane(float distance_from_movement_plane);
    void setAxialRotationTime(float time);
    void setOrbit(P<SpaceObject> target, float orbit_time);

    virtual string getExportLine() override;

protected:
    glm::mat4 getModelMatrix() const override;

private:
    //Config:
    float planet_size;
    float cloud_size;
    float atmosphere_size;
    string planet_texture;
    string cloud_texture;
    string atmosphere_texture;
    glm::u8vec4 atmosphere_color;
    float distance_from_movement_plane;

    float axial_rotation_time;
    int32_t orbit_target_id;
    float orbit_time;
    float orbit_distance;

    float collision_size;

    void updateCollisionSize();
};

#endif//PLANET_H
