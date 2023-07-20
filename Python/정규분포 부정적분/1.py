import scipy.special as sp
import numpy as np

# 평균과 표준편차
μ = 0
σ = 1

# x 값
x = 1.96

# 근사적인 누적분포함수 값 계산
cdf_approx = 0.5 * (1 + sp.erf((x - μ) / (σ * np.sqrt(2))))

# 결과 출력
print("근사적인 누적분포함수 값:", cdf_approx)
