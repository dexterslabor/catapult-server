/**
*** Copyright (c) 2016-present,
*** Jaguar0625, gimre, BloodyRookie, Tech Bureau, Corp. All rights reserved.
***
*** This file is part of Catapult.
***
*** Catapult is free software: you can redistribute it and/or modify
*** it under the terms of the GNU Lesser General Public License as published by
*** the Free Software Foundation, either version 3 of the License, or
*** (at your option) any later version.
***
*** Catapult is distributed in the hope that it will be useful,
*** but WITHOUT ANY WARRANTY; without even the implied warranty of
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*** GNU Lesser General Public License for more details.
***
*** You should have received a copy of the GNU Lesser General Public License
*** along with Catapult. If not, see <http://www.gnu.org/licenses/>.
**/

#pragma once
#include "ExecutionConfiguration.h"

namespace catapult { namespace chain {

	/// Function signature for validating and executing a batch of entity infos with a shared height and time and updating
	/// stateful information.
	using BatchEntityProcessor = std::function<validators::ValidationResult (
			Height,
			Timestamp,
			const model::WeakEntityInfos&,
			const observers::ObserverState&)>;

	/// Creates a batch entity processor around \a config.
	BatchEntityProcessor CreateBatchEntityProcessor(const ExecutionConfiguration& config);
}}
