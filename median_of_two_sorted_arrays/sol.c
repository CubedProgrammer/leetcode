struct result
{
	unsigned ui;
	unsigned vi;
};
struct result findMedian(const int *u, unsigned us, const int *v, unsigned vs)
{
	unsigned u_lo = 0, u_hi = us;
	unsigned v_lo = 0, v_hi = vs;
	unsigned half = (us + vs) / 2;
	while(u_hi > u_lo && v_hi > v_lo)
	{
		unsigned u_mid = (u_lo + u_hi) / 2;
		unsigned v_mid = (v_lo + v_hi) / 2;
		int x = u[u_mid];
		int y = v[v_mid];
		if(x < y)
		{
			if(u_mid + v_mid + 1 > half)
				v_hi = v_mid;
			else
				u_lo = u_mid + 1;
		}
		else
		{
			if(u_mid + v_mid + 1 > half)
				u_hi = u_mid;
			else
				v_lo = v_mid + 1;
		}
	}
	if(v_lo < v_hi)
		v_hi = v_lo = half - u_lo;
	else
		u_hi = u_lo = half - v_hi;
	struct result r = {u_lo, v_lo};
	return r;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	struct result indices = findMedian(nums1, nums1Size, nums2, nums2Size);
	double median;
	if(indices.ui == nums1Size)
		median = nums2[indices.vi];
	else if(indices.vi == nums2Size)
		median = nums1[indices.ui];
	else
		median = nums1[indices.ui] < nums2[indices.vi] ? nums1[indices.ui] : nums2[indices.vi];
	if((nums1Size + nums2Size) % 2 == 0)
	{
		if(indices.ui == 0)
			median += nums2[indices.vi - 1];
		else if(indices.vi == 0)
			median += nums1[indices.ui - 1];
		else
			median += nums1[indices.ui - 1] < nums2[indices.vi - 1] ? nums2[indices.vi - 1] : nums1[indices.ui - 1];
		median *= 0.5;
	}
	return median;
}
