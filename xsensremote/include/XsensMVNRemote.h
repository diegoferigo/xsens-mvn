/*
 * Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 */

#ifndef YARP_XSENSMVNREMOTE_H
#define YARP_XSENSMVNREMOTE_H

#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/IFrameProvider.h>
#include <yarp/dev/IIMUFrameProvider.h>
#include <yarp/dev/IXsensMVNInterface.h>
#include <yarp/dev/PreciselyTimed.h>

namespace yarp {
    namespace dev {
        class XsensMVNRemote;
    }
} // namespace yarp

class yarp::dev::XsensMVNRemote
    : public yarp::dev::DeviceDriver
    , public yarp::dev::IPreciselyTimed
    , public yarp::experimental::dev::IFrameProvider
    , public yarp::experimental::dev::IIMUFrameProvider
    , public yarp::experimental::dev::IXsensMVNInterface
{
    class XsensMVNRemotePrivate;
    XsensMVNRemotePrivate* m_pimpl;

public:
    XsensMVNRemote();
    virtual ~XsensMVNRemote();

    // DeviceDriver interface
    bool open(yarp::os::Searchable& config);
    bool close();

    // IPreciselyTimed interface
    virtual yarp::os::Stamp getLastInputStamp();

    // IFrameProvider interface
    virtual std::vector<yarp::experimental::dev::FrameReference> frames();

    virtual yarp::experimental::dev::IFrameProviderStatus
    getFramePoses(std::vector<yarp::sig::Vector>& segmentPoses);
    virtual yarp::experimental::dev::IFrameProviderStatus
    getFrameVelocities(std::vector<yarp::sig::Vector>& segmentVelocities);
    virtual yarp::experimental::dev::IFrameProviderStatus
    getFrameAccelerations(std::vector<yarp::sig::Vector>& segmentAccelerations);
    virtual yarp::experimental::dev::IFrameProviderStatus
    getFrameInformation(std::vector<yarp::sig::Vector>& segmentPoses,
                        std::vector<yarp::sig::Vector>& segmentVelocities,
                        std::vector<yarp::sig::Vector>& segmentAccelerations);

    // IIMUFrameProvider interface
    virtual std::vector<yarp::experimental::dev::IMUFrameReference> IMUFrames();

    virtual yarp::experimental::dev::IIMUFrameProviderStatus
    getIMUFrameOrientations(std::vector<yarp::sig::Vector>& imuOrientations);
    virtual yarp::experimental::dev::IIMUFrameProviderStatus
    getIMUFrameAngularVelocities(std::vector<yarp::sig::Vector>& imuAngularVelocities);
    virtual yarp::experimental::dev::IIMUFrameProviderStatus
    getIMUFrameLinearAccelerations(std::vector<yarp::sig::Vector>& imuLinearAccelerations);
    virtual yarp::experimental::dev::IIMUFrameProviderStatus
    getIMUFrameMagneticFields(std::vector<yarp::sig::Vector>& imuMagneticFields);
    virtual yarp::experimental::dev::IIMUFrameProviderStatus
    getIMUFrameInformation(std::vector<yarp::sig::Vector>& imuOrientations,
                           std::vector<yarp::sig::Vector>& imuAngularVelocities,
                           std::vector<yarp::sig::Vector>& imuLinearAccelerations,
                           std::vector<yarp::sig::Vector>& imuMagneticFields);

    // IXsensMVNInterface interface
    virtual bool setBodyDimensions(const std::map<std::string, double>& dimensions);
    virtual bool setBodyDimension(const std::string& bodyPart, const double dimension);
    virtual std::map<std::string, double> bodyDimensions();

    virtual bool calibrate(const std::string& calibrationType = "");
    virtual bool abortCalibration();

    virtual bool startAcquisition();
    virtual bool stopAcquisition();
};

#endif /* end of include guard: YARP_XSENSMVNREMOTE_H */
