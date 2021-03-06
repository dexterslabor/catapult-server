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
#include "plugins/txes/namespace/src/model/MosaicInfo.h"
#include "plugins/txes/namespace/src/model/NamespaceInfo.h"
#include "catapult/ionet/PackedNodeInfo.h"
#include "catapult/model/AccountInfo.h"
#include "catapult/model/DiagnosticCounterValue.h"
#include "catapult/model/RangeTypes.h"
#include "catapult/state/TimestampedHash.h"
#include "catapult/thread/Future.h"

namespace catapult { namespace ionet { class PacketIo; } }

namespace catapult { namespace extensions {

	/// An api for retrieving diagnostic information from a remote node.
	class RemoteDiagnosticApi {
	private:
		template<typename T>
		using future = thread::future<T>;

	public:
		virtual ~RemoteDiagnosticApi() {}

	public:
		/// Gets account infos for all accounts with addresses in \a addresses.
		virtual future<model::AccountInfoRange> accountInfos(model::AddressRange&& addresses) const = 0;

		/// Gets all timestamped hashes in \a timestampedHashes that are unconfirmed, i.e. not in the hash cache.
		virtual future<state::TimestampedHashRange> confirmTimestampedHashes(state::TimestampedHashRange&& timestampedHashes) const = 0;

		/// Gets current diagnostic counter values.
		virtual future<model::EntityRange<model::DiagnosticCounterValue>> diagnosticCounters() const = 0;

		/// Gets node infos for all active nodes
		virtual future<model::EntityRange<ionet::PackedNodeInfo>> activeNodeInfos() const = 0;

		/// Gets namespace infos for all namespace ids in \a namespaceIds.
		virtual future<model::EntityRange<model::NamespaceInfo>> namespaceInfos(model::EntityRange<NamespaceId>&& namespaceIds) const = 0;

		/// Gets mosaic infos for all mosaic ids in \a mosaicIds.
		virtual future<model::EntityRange<model::MosaicInfo>> mosaicInfos(model::EntityRange<MosaicId>&& mosaicIds) const = 0;
	};

	/// Creates a diagnostic api for interacting with a remote node with the specified \a io.
	std::unique_ptr<RemoteDiagnosticApi> CreateRemoteDiagnosticApi(ionet::PacketIo& io);
}}
