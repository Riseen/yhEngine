// 230920 기준 삼각형 vertex shader 뿐


struct VTX_IN
{
    float3 vPos : POSITION;
    float4 vColor : COLOR;
};

struct VTX_OUT
{
    float4 vPos : SV_Position;
    float4 vColor : COLOR;
};

cbuffer TRANSFORM : register(b0) // 레지스터 번호, 그래픽 카드의 기능을 쓰겠다.
{
    float3 cbPos; // 그래픽 카드는 16byte 단위로 읽기 때문에 
    int padd1; // 16byte를 채워주기 위해 int 잉여 값을 하나 넣어 주어 그다음 값을 침범하지못하게한다.
    float3 cbScale;
    int padd2;
};

VTX_OUT VS_Test(VTX_IN _in)
{
    VTX_OUT output = (VTX_OUT) 0.f;
    
    output.vPos = float4(_in.vPos + cbPos.xyz, 1.f); // 위치 + 위치.xyz, 상수버퍼 값을 더해서 이동 시켜주는것
    output.vPos.xyz *= cbScale; // scale(크기 값) 적용, 위치 * 값 ex) xyz * 1.5 로 정점위치를 다옮겨서 크기를 키우는것
    
    output.vColor = _in.vColor;
    
    return output;
}
