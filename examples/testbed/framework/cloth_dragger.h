/*
* Copyright (c) 2016-2019 Irlan Robson https://irlanrobson.github.io
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef B3_CLOTH_DRAGGER_H
#define B3_CLOTH_DRAGGER_H

#include <bounce/common/geometry.h>
#include <bounce/cloth/cloth.h>
#include <bounce/cloth/cloth_mesh.h>
#include <bounce/cloth/particle.h>
#include <bounce/cloth/cloth_triangle.h>
#include <bounce/cloth/forces/mouse_force.h>

// A cloth triangle dragger.
class b3ClothDragger
{
public:
	b3ClothDragger(b3Ray3* ray, b3Cloth* cloth);
	~b3ClothDragger();

	void SetStaticDrag(bool bit);

	bool GetStaticDrag() const;

	void SetMouseStiffness(float32 k);

	float32 GetMouseStiffness();

	void SetMouseDamping(float32 k);

	float32 GetMouseDamping();
	
	bool IsDragging() const;

	bool StartDragging();

	void Drag();

	void StopDragging();

	b3Vec3 GetPointA() const;

	b3Vec3 GetPointB() const;
private:
	b3Ray3* m_ray;
	float32 m_x;

	b3Cloth* m_cloth;
	const b3ClothMesh* m_mesh;
	u32 m_triangleIndex;
	b3ClothMeshTriangle* m_triangle;
	float32 m_u, m_v;

	float32 m_km;
	float32 m_kd;
	b3Particle* m_particle;
	b3MouseForce* m_mf;

	bool m_staticDrag;
	b3ParticleType m_t1, m_t2, m_t3;
};

inline bool b3ClothDragger::GetStaticDrag() const
{
	return m_staticDrag;
}

inline void b3ClothDragger::SetMouseStiffness(float32 k)
{
	m_km = k;
}

inline float32 b3ClothDragger::GetMouseStiffness()
{
	return m_km;
}

inline void b3ClothDragger::SetMouseDamping(float32 k)
{
	m_kd = k;
}

inline float32 b3ClothDragger::GetMouseDamping()
{
	return m_kd;
}

inline bool b3ClothDragger::IsDragging() const
{
	return m_triangle != nullptr;
}

#endif