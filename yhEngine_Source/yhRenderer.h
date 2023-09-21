#pragma once
#include "yhEnum.h"
#include "CommonInclude.h"
#include "yhHeader.h"
#include "yhMath.h"
#include "yhGraphicsDevice_DX11.h"

#include "yhMesh.h"
#include "yhShader.h"
#include "yhConstantBuffer.h"

using namespace yh::graphics;
using namespace yh::enums;
using namespace yh::math;

namespace yh::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Vector3 pos;
		int padd1;

		Vector3 scale;
		int padd2;
	};

	extern Mesh* mesh;
	extern Shader* shader;
	extern ConstantBuffer* constantBuffers[];

	// Initialize the renderer
	void Initialize();
	void Release();
}
