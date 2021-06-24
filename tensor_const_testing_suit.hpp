#pragma once

#include <iostream>
#include "tensor.hpp"

namespace tensor_const_testing_suit
{
	using namespace tensor_lib;

	void TEST_1()
	{
		tensor<int, 3> tsor( 2u, 2u, 2u );

		[](const tensor<int, 3>& tsor)
		{
			if (not std::is_same_v<decltype(tsor[0]), const const_subdimension<int, 2>>)
			{
				throw std::exception("TEST_1 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 1 PASSED.\n";
		}(tsor);
	}

	void TEST_2()
	{
		tensor<int, 3> tsor( 2u, 2u, 2u );

		[](tensor<int, 3>& tsor)
		{
			if (not std::is_same_v<decltype(tsor[0]), subdimension<int, 2>>)
			{
				throw std::exception("TEST_2 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 2 PASSED.\n";
		}(tsor);
	}

	void TEST_3()
	{
		tensor<int, 3> tsor( 2u, 2u, 2u );

		[](const subdimension<int, 2>& subdim)
		{
			if (not std::is_same_v<decltype(subdim[0]), const const_subdimension<int, 1>>)
			{
				throw std::exception("TEST_3 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 3 PASSED.\n";
		}(tsor[0]);
	}

	void TEST_4()
	{
		tensor<int, 3> tsor( 2u, 2u, 2u );
		auto subdim = tsor[0];

		[](subdimension<int, 2>& subdim)
		{
			if (not std::is_same_v<decltype(subdim[0]), subdimension<int, 1>>)
			{
				throw std::exception("TEST_4 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 4 PASSED.\n";
		}(subdim);
	}

	void TEST_5()
	{
		tensor<int, 3> tsor( 2u, 2u, 2u );
		const_subdimension<int, 3> subdim(tsor);

		[](const const_subdimension<int, 3>& subdim)
		{
			if (not std::is_same_v<decltype(subdim[0]), const const_subdimension<int, 2>>)
			{
				throw std::exception("TEST_5 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 5 PASSED.\n";
		}(subdim);
	}

	void TEST_6()
	{
		tensor<int, 3> tsor( 2u, 2u, 2u );
		
		[](const tensor<int, 3>& tsor)
		{
			if (not std::is_same_v<decltype(tsor[0][0][0]), const int &>)
			{
				throw std::exception("TEST_6 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 6 PASSED.\n";
		}(tsor);
	}

	void TEST_7()
	{
		tensor<int, 3> tsor( 2u, 2u, 2u );
		subdimension<int, 3> subdim(tsor);

		[](const subdimension<int, 3>& subdim)
		{
			if (not std::is_same_v<decltype(subdim[0][0][0]), const int&>)
			{
				throw std::exception("TEST_7 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 7 PASSED.\n";
		}(subdim);
	}

	void TEST_8()
	{
		tensor<int, 3> tsor(2u, 2u, 2u);
		const_subdimension<int, 3> subdim(tsor);

		[](const const_subdimension<int, 3>& subdim)
		{
			if (not std::is_same_v<decltype(subdim[0][0][0]), const int&>)
			{
				throw std::exception("TEST_8 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 8 PASSED.\n";
		}(subdim);
	}

	void TEST_9()
	{
		tensor<int, 3> tsor(2u, 2u, 2u);

		[](tensor<int, 3>& tsor)
		{
			if (not std::is_same_v<decltype(tsor[0][0][0]), int&>)
			{
				throw std::exception("TEST_9 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 9 PASSED.\n";
		}(tsor);
	}

	void TEST_10()
	{
		tensor<int, 3> tsor(2u, 2u, 2u);
		subdimension<int, 3> subdim(tsor);

		[](subdimension<int, 3>& subdim)
		{
			if (not std::is_same_v<decltype(subdim[0][0][0]), int&>)
			{
				throw std::exception("TEST_10 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 10 PASSED.\n";
		}(subdim);
	}

	void TEST_11()
	{
		tensor<int, 3> tsor(2u, 2u, 2u);

		[](tensor<int, 3>& tsor)
		{
			auto it = tsor.begin();

			if (not std::is_same_v<decltype(it), tensor<int, 3>::iterator>)
			{
				throw std::exception("TEST_11 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 11 PASSED.\n";
		}(tsor);
	}

	void TEST_12()
	{
		tensor<int, 3> tsor(2u, 2u, 2u);

		[](const tensor<int, 3>& tsor)
		{
			auto it = tsor.begin();

			if (not std::is_same_v<decltype(it), tensor<int, 3>::const_iterator>)
			{
				throw std::exception("TEST_12 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 12 PASSED.\n";
		}(tsor);
	}

	void TEST_13()
	{
		tensor<int, 3> tsor(2u, 2u, 2u);

		[](tensor<int, 3>& tsor)
		{
			auto it = tsor[0].begin();

			if (not std::is_same_v<decltype(it), std::span<int>::iterator>)
			{
				throw std::exception("TEST_13 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 13 PASSED.\n";
		}(tsor);
	}

	void TEST_14()
	{
		tensor<int, 3> tsor(2u, 2u, 2u);

		[](const tensor<int, 3>& tsor)
		{
			auto it = tsor[0].begin();

			if (not std::is_same_v<decltype(it), std::span<const int>::iterator>)
			{
				throw std::exception("TEST_14 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 14 PASSED.\n";
		}(tsor);
	}

	void TEST_15()
	{
		tensor<int, 3> tsor(2u, 2u, 2u);

		[](tensor<int, 3>& tsor)
		{
			auto it = tsor.cbegin();

			if (not std::is_same_v<decltype(it), tensor<int, 3>::const_iterator>)
			{
				throw std::exception("TEST_15 in 'tensor_const_testing_suit' failed!\n");
			}
			else
				std::cout << "\tTEST 15 PASSED.\n";
		}(tsor);
	}

	void RUN_ALL()
	{
		std::cout << "Running tensor const correctness tests...\n\n";

		TEST_1();
		TEST_2();
		TEST_3();
		TEST_4();
		TEST_5();
		TEST_6();
		TEST_7();
		TEST_8();
		TEST_9();
		TEST_10();
		TEST_11();
		TEST_12();
		TEST_13();
		TEST_14();
		TEST_15();

		std::cout << "\n";
	}
}