/*****************************************************************
 * 选择排序
 * 
 * @author liwenwei
 * 
 ****************************************************************/
package com.liwenwei.algs4.code;

import java.util.Arrays;

public class Selection {

	public static void sort(Comparable[] a) {
		for (int i = 0; i < a.length; i++) {
			int min = i;
			for (int j = i + 1; j < a.length; j++) {
				if (less(a[j], a[min])) {
					min = j;
				}
			}
			exch(a, i, min);
		}
	}

	private static boolean less(Comparable v, Comparable w) {
		return v.compareTo(w) < 0;
	}

	private static void exch(Comparable[] a, int i, int j) {
		Comparable t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	public static boolean isSorted(Comparable[] a) {
		for (int i = 1; i < a.length; i++) {
			if (less(a[i], a[i - 1]))
				return false;
		}
		return true;
	}

	public static void main(String[] args) {
		Integer[] a = { 6, 4, 10, 9, 7, 7, 8, 10, 8, 9, 10 };
		Selection.sort(a);
		System.out.println(Arrays.toString(a));
	}

}
