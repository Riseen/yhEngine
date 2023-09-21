// 230920 기준 삼각형 관련 pixel shader 뿐

struct VTX_OUT
{
    float4 vPos : SV_Position;
    float4 vColor : COLOR;
};


float4 PS_Test(VTX_OUT _in) : SV_Target
{
    return _in.vColor;
}