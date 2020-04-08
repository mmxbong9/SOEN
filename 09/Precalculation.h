#pragma once

namespace SOEN
{
	// 태양(S)이 중간에 있고, 그 주위를 지구(E) 10도씩 0.1sec 마다 회전하는 로직 (업데이트시 매번 계산)
	void ExecuteCircleMovement();

	// ExecuteCircleMovement 에서 계산 하는 부분의 값을 미리 계산 하여 들고 있고, 0.1sec 마다 계산 되어있는 값을 적용.
	void ExecutePrecalculationCircleMovement();
}
